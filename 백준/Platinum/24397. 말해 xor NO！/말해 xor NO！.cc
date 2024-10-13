#include <iostream>
#include <algorithm>
using namespace std;

int n, m, k;
long long res;
struct node {
	int cnt = 0, K = 0;
	node* child[2] = { nullptr, };
};

node* root;


void check(int x) {
	node* cur = root;
	for (int i = 30; i >= 0; i--) {
		if (cur == nullptr) break;
		int y = x & (1 << i);
		int f = y ? 1 : 0;
		int K = k & (1 << i);
		if (K) {
			if (f) {
				if (cur->child[f]) res += cur->child[f]->cnt;
				cur = cur->child[!f];
			}
			else {
				if (cur->child[f]) res += cur->child[f]->cnt;
				cur = cur->child[!f];
			}
		}
		else {
			cur = cur->child[f];
		}
	}
}

void insert(int x) {
	node* cur = root;
	for (int i = 30; i >= 0; i--) {
		int y = x & (1 << i);
		if (y) y = 1;

		if (cur->child[y] == nullptr) {
			cur->child[y] = new node;
		}
		cur = cur->child[y];
		cur->cnt++;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	root = new node;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		insert(x);
	}
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		check(x);
	}
	cout << res << '\n';
	return 0;
}
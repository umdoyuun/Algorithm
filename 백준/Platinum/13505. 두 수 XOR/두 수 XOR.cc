#include <iostream>
#include <algorithm>
using namespace std;

int n;
struct node {
	node* child[2] = { nullptr, };
};

node* root;


int check(int x) {
	node* cur = root;
	int ret = 0;
	for (int i = 30; i >= 0; i--) {
		int y = x & (1 << i);
		int f = y ? 1 : 0;
		if (cur->child[!f]) {
			ret += (1 << i);
			cur = cur->child[!f];
		}
		else {
			cur = cur->child[f];
		}
	}
	return ret;
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
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	root = new node;
	int res = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		insert(x);
		res = max(res, check(x));
	}
	cout << res << '\n';
	return 0;
}
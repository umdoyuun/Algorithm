#include <iostream>
#include <algorithm>
using namespace std;

int n, res;
struct node {
	node* child[2];
};

node* root;
node pool[5000000];
int cnt;

node* new_node() {
	pool[cnt].child[0] = nullptr;
	pool[cnt].child[1] = nullptr;
	return &pool[cnt++];
}

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
            if (res >= ret + (1 << i)) return 0;
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
			cur->child[y] = new_node();
		}
		cur = cur->child[y];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	root = new_node();

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		insert(x);
		res = max(res, check(x));
	}
	cout << res << '\n';
	return 0;
}
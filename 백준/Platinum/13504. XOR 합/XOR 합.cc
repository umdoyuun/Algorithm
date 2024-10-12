#include <iostream>
#include <algorithm>
using namespace std;

int n;
struct node {
	node* child[2] = { nullptr, };
};

node pool[5000000];
int cnt;
node* root;


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
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cnt = 0;
		cin >> n;
		root = new_node();
		int res = 0;
		int tmp = 0;
		insert(0);
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			tmp ^= x;
			insert(tmp);
			res = max(res, check(tmp));

		}
		cout << res << '\n';
	}
	return 0;
}
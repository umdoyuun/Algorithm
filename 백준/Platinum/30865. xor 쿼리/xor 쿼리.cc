#include <iostream>
using namespace std;

int n, m;
int arr[100001];
struct Trie {
	int cnt = 0;
	Trie* child[2] = {nullptr, };
};

Trie* root = new Trie();

void insert(int x) {
	Trie* cur = root;
	for (int i = 31; i >= 0; i--) {
		int y = (x & (1 << i)) ? 1 : 0;
		if (!cur->child[y]) {
			cur->child[y] = new Trie();
		}
		cur = cur->child[y];
		cur->cnt++;
	}
}

void erase(int x) {
	Trie* cur = root;
	for (int i = 31; i >= 0; i--) {
		int y = (x & (1 << i)) ? 1 : 0;
		cur = cur->child[y];
		cur->cnt--;
	}
}

int query(int x, int k) {
	Trie* cur = root;
	int ret = 0;
	for (int i = 31; i >= 0; i--) {
		int y = (x & (1 << i)) ? 1 : 0;
		if (cur->child[!y] && cur->child[!y]->cnt) {
			if (cur->child[!y]->cnt >= k) {
				cur = cur->child[!y];
				ret |= (1 << i);
			}
			else {
				k -= cur->child[!y]->cnt;
				cur = cur->child[y];
			}
		}
		else {
			cur = cur->child[y];
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		insert(arr[i]);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int cmd, x, y;
		cin >> cmd >> x >> y;
		if (cmd == 1) {
			erase(arr[x]);
			arr[x] = y;
			insert(y);
		}
		else {
			cout << query(y, x) << '\n';
		}
	}
	return 0;
}
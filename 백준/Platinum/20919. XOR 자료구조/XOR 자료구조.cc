#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
using namespace std;

int n, q, p_cnt;
set<int> s;
struct Trie {
	int cnt;
	Trie* child[2];
};
Trie pool[1000000];
Trie* root;

Trie* new_Trie() {
	pool[p_cnt].cnt = 0;
	pool[p_cnt].child[0] = nullptr;
	pool[p_cnt].child[1] = nullptr;
	return &pool[p_cnt++];
}

void init() {
	s.clear();
	p_cnt = 0;
	root = new_Trie();
}

void insert(int x) {
	Trie* cur = root;
	cur->cnt++;
	for (int i = 25; i >= 0; i--) {
		int y = (x & (1 << i)) ? 1 : 0;
		if (!cur->child[y]) {
			cur->child[y] = new_Trie();
		}
		cur = cur->child[y];
		cur->cnt++;
	}
}

int remove_min() {
	Trie* cur = root;
	int ret = 0;
	cur->cnt--;
	for (int i = 25; i >= 0; i--) {
		if (cur->child[0] && cur->child[0]->cnt > 0) {
			cur = cur->child[0];
		}
		else {
			cur = cur->child[1];
			ret |= (1 << i);
		}
		cur->cnt--;
	}
	return ret;
}

int remove_max() {
	Trie* cur = root;
	int ret = 0;
	cur->cnt--;
	for (int i = 25; i >= 0; i--) {
		if (cur->child[1] && cur->child[1]->cnt) {
			ret |= (1 << i);
			cur = cur->child[1];
		}
		else {
			cur = cur->child[0];
		}
		cur->cnt--;
	}
	return ret;
}

int find_min(int x) {
	Trie* cur = root;
	int ret = 0;
	for (int i = 25; i >= 0; i--) {
		int y = (x & (1 << i)) ? 1 : 0;
		if (cur->child[y] && cur->child[y]->cnt) {
			cur = cur->child[y];
		}
		else {
			cur = cur->child[!y];
			ret |= (1 << i);
		}
	}
	return ret;
}

int find_max(int x) {
	Trie* cur = root;
	int ret = 0;
	for (int i = 25; i >= 0; i--) {
		int y = (x & (1 << i)) ? 1 : 0;
		if (cur->child[!y] && cur->child[!y]->cnt) {
			cur = cur->child[!y];
			ret |= (1 << i);
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
	//freopen("sample_input.txt", "r", stdin);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		init();
		cin >> n >> q;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			s.insert(x);
		}
		for (auto it = s.begin(); it != s.end(); it++) {
			insert(*it);
		}
		for (int i = 0; i < q; i++) {
			int cmd;
			cin >> cmd;
			if (cmd == 1) {
				int v;
				cin >> v;
				cout << find_min(v) << '\n';
			}
			else if (cmd == 2) {
				int v;
				cin >> v;
				cout << find_max(v) << '\n';
			}
			else if (cmd == 3) {
				int v;
				cin >> v;
				if (s.find(v) == s.end()) {
					s.insert(v);
					insert(v);
				}
				cout << root->cnt << '\n';
			}
			else if (cmd == 4) {
				int ret = remove_min();
				s.erase(ret);
				cout << ret << '\n';
			}
			else {
				int ret = remove_max();
				s.erase(ret);
				cout << ret << '\n';
			}
		}
	}
	return 0;
}
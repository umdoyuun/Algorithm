#include <iostream>
#include <string>
#include <map>
using namespace std;

int n, m, res;

struct Trie {
	int cnt = 0;
	bool isEnd = false;
	map<char, Trie*> child;
};

Trie* root;
Trie pool[100000];
int p_cnt;

Trie* new_node() {
	pool[p_cnt].cnt = 0;
	pool[p_cnt].isEnd = false;
	pool[p_cnt].child.clear();
	return &pool[p_cnt++];
}

void init() {
	p_cnt = 0;
	root = new_node();
	res = 0;
}

void insert_trie(string str) {
	Trie* cur = root;
	int s = str.size();
	for (int i = 0; i < s; i++) {
		char c = str[i];
		if (cur->child.find(c) == cur->child.end()) {
			cur->child[c] = new_node();
		}
		cur = cur->child[c];
	}
	cur->isEnd = true;
	return;
}

void set_trie(string str) {
	Trie* cur = root;
	int s = str.size();
	for (int i = 0; i < s; i++) {
		char c = str[i];
		cur->cnt++;
		if (cur->child.find(c) == cur->child.end()) {
			cur->child[c] = new_node();
		}
		cur = cur->child[c];
	}
	cur->cnt++;
}

void check(Trie* cur) {
	if (cur->cnt == 0) {
		res++;
		return;
	}
	else if(cur->isEnd){
		res++;
	}
	for (auto iter = cur->child.begin(); iter != cur->child.end(); iter++) {
		check(iter->second);
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		init();
		cin >> n;
		string str;
		for (int i = 0; i < n; i++) {
			cin >> str;
			insert_trie(str);
		}
		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> str;
			set_trie(str);
		}
		check(root);
		cout << res << '\n';
	}
	return 0;
}
#include <iostream>
#include <map>
#include <unordered_set>
#include <string>
using namespace std;

int c, n, m;

struct Trie {
	bool isEnd, lastWord;
	map<char, Trie*> child;
};

Trie pool[5000000];
int p_cnt;
Trie* root;
unordered_set<string> us;

Trie* new_trie() {
	pool[p_cnt].isEnd = false;
	pool[p_cnt].lastWord = true;
	return &pool[p_cnt++];
}

void make_trie(string str) {
	Trie* cur = root;
	for (int i = 0; i < str.size(); i++) {
		char c = str[i];
		if (cur->child.find(c) == cur->child.end()) {
			cur->child[c] = new_trie();
			cur->lastWord = false;
			cur = cur->child[c];
		}
		else {
			cur = cur->child[c];
		}
	}
	cur->isEnd = true;
}

bool find(string str) {
	Trie* cur = root;
	for (int i = 0; i < str.size(); i++) {
		char c = str[i];
		if (cur->child.find(c) == cur->child.end()) {
			return false;
		}
		else {
			cur = cur->child[c];
			if (cur->isEnd) {
				string tmp = str.substr(i + 1);
				if (us.count(tmp)) {
					return true;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	root = new_trie();
	cin >> c >> n;
	for (int i = 0; i < c; i++) {
		string str;
		cin >> str;
		make_trie(str);
	}
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		us.insert(str);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		if (find(str)) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}
	return 0;
}
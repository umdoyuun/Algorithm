#include <iostream>
#include <string>
#include <map>
using namespace std;

struct Trie {
	int cnt, isEnd;
	map<char, Trie*> child;
};

Trie *root;
int n, p_cnt;
Trie pool[5000000];

Trie* new_trie() {
	pool[p_cnt].cnt = 0;
	pool[p_cnt].isEnd = 0;
	return &pool[p_cnt++];
}

void print(string str) {
	cout << str << '\n';
}

void make_trie(string str) {
	Trie* cur = root;
	bool flag = true;
	for (int i = 0; i < str.size(); i++) {
		char x = str[i];
		if (cur->child.find(x) == cur->child.end()) {
			cur->child[x] = new_trie();
			if (flag) {
				print(str.substr(0, i + 1));
				flag = false;
			}
		}
		cur = cur->child[x];
		cur->cnt++;		
	}
	cur->isEnd++;
	if (flag) {
		if(cur->isEnd > 1)
			print(str + to_string(cur->isEnd));
		else
			print(str);
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	string str;
	root = new_trie();
	for (int i = 0; i < n; i++) {
		cin >> str;
		make_trie(str);
	}
	return 0;
}
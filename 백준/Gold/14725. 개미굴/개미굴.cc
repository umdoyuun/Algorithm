#include <iostream>
#include <map>
#include <string>
using namespace std;

struct trie {
	map<string, trie*> m;
};

trie* root = new trie();
int n;

void make_trie(int x) {
	string str;
	trie* cur = root;

	for (int i = 0; i < x; i++) {
		cin >> str;
		if (cur->m.find(str) == cur->m.end()) {
			cur->m[str] = new trie();
		}
		cur = cur->m[str];
	}
}

void print_trie(trie* cur, int cnt) {
	for (auto iter = cur->m.begin(); iter != cur->m.end(); iter++) {
		for (int i = 0; i < cnt; i++) {
			cout << "--";
		}
		cout << iter->first << '\n';
		print_trie(iter->second, cnt + 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		make_trie(x);
	}
	print_trie(root, 0);
	return 0;
}
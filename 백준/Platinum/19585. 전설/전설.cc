#include <iostream>
#include <string>
#include <map>
#include <unordered_set>
#include <algorithm>
using namespace std;

int n, m, q;
bool res;

struct node {
	bool end;
	map<char, node*> Map;
};

unordered_set<string> s;
node* color_root;
node* nick_root;

node* new_node() {
	node* nd = new node();
	nd->end = false;
	return nd;
}

void color_trie(string str) {
	node* cur = color_root;
	for (int i = 0; i < str.size(); i++) {
		if (cur->Map.find(str[i]) == cur->Map.end()) {
			cur->Map[str[i]] = new_node();
		}
		cur = cur->Map[str[i]];
	}
	cur->end = true;
}

void nick_trie(string str) {
	node* cur = nick_root;
	for (int i = 0; i < str.size(); i++) {
		if (cur->Map.find(str[i]) == cur->Map.end()) {
			cur->Map[str[i]] = new_node();
		}
		cur = cur->Map[str[i]];
	}
	cur->end = true;
}

void check_nick(string str, int idx) {
	node* cur = nick_root;
	for (int i = idx; i < str.size(); i++) {
		if (cur->Map.find(str[i]) == cur->Map.end()) {
			return;
		}
		else {
			cur = cur->Map[str[i]];
		}
	}
	if (cur->end) res = true;
}


void check(string str) {
	node* cur = color_root;
	for (int i = 0; i < str.size(); i++) {
		if (cur->end) {
			if (!res)
				//check_nick(str, i);
				if (s.count(str.substr(i))) {
					res = true;
				}
		}
		if (cur->Map.find(str[i]) == cur->Map.end()) {
			return;
		}
		else {
			cur = cur->Map[str[i]];
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	color_root = new_node();
	nick_root = new_node();
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		color_trie(str);
	}
	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		s.insert(str);
		//nick_trie(str);
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		string str;
		cin >> str;
		res = false;
		check(str);
		if (res) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}
	return 0;
}
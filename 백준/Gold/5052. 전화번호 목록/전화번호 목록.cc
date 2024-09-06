#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;
bool res;
//vector<string> v;

struct Trie {
	bool isEnd;
	int cnt;
	Trie* child[10];
};

Trie trie[100000];
int p_cnt = 0;
Trie* root[10];

Trie* new_trie() {
	trie[p_cnt].isEnd = false;
	trie[p_cnt].cnt = 0;
	for (register int i = 0; i < 10; i++) {
		trie[p_cnt].child[i] = nullptr;
	}
	return &trie[p_cnt++];
}

bool cmp(string a, string b) {
	return a.size() > b.size();
}

void init() {
	p_cnt = 0;
	//v.clear();
	res = true;
	for (int i = 0; i < 10; i++) {
		root[i] = new_trie();
	}
}



void insert_trie(string str) {
	Trie* cur = root[str[0] - 48];
	for (int i = 1; i < str.size(); i++) {
		int x = str[i] - 48;
		if (cur->isEnd) {
			res = false;
			return;
		}
		if (cur->child[x]) {
			cur = cur->child[x];	
		}
		else {
			cur->child[x] = new_trie();
			cur->cnt++;
			cur = cur->child[x];

		}

	}
	cur->isEnd = true;
	if (cur->cnt > 0) res = false;
}

//void func() {
//	for (int i = 0; i < n; i++) {
//		if (!res) return;
//		insert_trie(v[i]);
//	}
//}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tc;

	cin >> tc;
	while (tc--) {
		init();
		cin >> n;
		for (int i = 0; i < n; i++) {
			string str;
			cin >> str;
			if (res) {
				insert_trie(str);
			}
			//v.push_back(str);
		}
		//sort(v.begin(), v.end(), cmp);
		//func();
		if (res) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
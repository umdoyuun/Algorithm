#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstring>
using namespace std;

int n, m, res_cnt, res;
string res_str;
char cube[4][4];
vector<string> v;
bool visit[300001];
bool cube_visit[4][4];

int dx[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dy[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

struct Trie {
	int isWord;
	bool isEnd;
	map<char, Trie*> child;
};

Trie trie[300000 * 8];
int p_cnt = 0, idx = 1;
Trie *root[26];

Trie *new_trie() {
	trie[p_cnt].isWord = 0;
	trie[p_cnt].isEnd = true;
	return &trie[p_cnt++];
}

void insert_trie(string str) {
	Trie *cur = root[str[0] - 65];
	for (int i = 1; i < str.size(); i++) {
		if (cur->child.find(str[i]) == cur->child.end()) {
			cur->child[str[i]] = new_trie();
			cur->isEnd = false;
			cur = cur -> child[str[i]];
		}
		else {
			cur = cur->child[str[i]];
		}
	}
	cur->isWord = idx++;
}

void dfs(int x, int y, int cnt, Trie *t) {
	if (t->isWord && !visit[t->isWord-1]) {
		visit[t->isWord - 1] = true;
		res_cnt++;

		switch (cnt) {
		case 3:
			res += 1;
			break;
		case 4:
			res += 1;
			break;
		case 5:
			res += 2;
			break;
		case 6:
			res += 3;
			break;
		case 7:
			res += 5;
			break;
		case 8:
			res += 11;
			break;
		}
		if (res_str.size() < v[t->isWord - 1].size()) {
			res_str = v[t->isWord - 1];
		}
		else if (res_str.size() == v[t->isWord - 1].size()) {
			if (res_str > v[t->isWord - 1]) {
				res_str = v[t->isWord - 1];
			}
		}
	}
	if (t->isEnd) return;
	
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4) continue;
		if (cube_visit[nx][ny]) continue;
		char c = cube[nx][ny];
		if (t->child.find(c) != t->child.end()) {
			cube_visit[nx][ny] = true;
			dfs(nx, ny, cnt + 1, t->child[c]);
			cube_visit[nx][ny] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < 26; i++) {
		root[i] = new_trie();
	}
	cin >> n;
	for (register int i = 0; i < n; i++) {
		string str;
		cin >> str;
		v.push_back(str);
		insert_trie(str);
	}
	cin >> m;
	for (register int b = 0; b < m; b++) {
		memset(visit, false, sizeof(visit));
		res_cnt = 0;
		res = 0;
		res_str = "";
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> cube[i][j];
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				memset(cube_visit, false, sizeof(cube_visit));
				cube_visit[i][j] = true;
				dfs(i, j, 1, root[cube[i][j] - 65]);
			}
		}
		cout << res << ' ' << res_str << ' ' << res_cnt << '\n';
	}
	return 0;
}
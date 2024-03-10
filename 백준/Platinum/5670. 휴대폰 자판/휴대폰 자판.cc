#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
double res;
vector<string> v;

struct node {
	int cnt;
	bool end;
	node* child[26];
};
node* root;
node pool[500000];
int p_cnt;

node* new_node() {
	pool[p_cnt].cnt = 0;
	pool[p_cnt].end = false;
	for (int i = 0; i < 26; i++) pool[p_cnt].child[i] = nullptr;
	return &pool[p_cnt++];
}

void init() {
	v.clear();
	p_cnt = 0;
	root = new_node();
	res = 0;
}


void make_trie(string str) {
	node* cur = root;
	for (int i = 0; i < str.size(); i++) {
		int x = str[i] - 'a';
		if (cur->child[x] == nullptr) {
			cur->cnt++;
			cur->child[x] = new_node();
		}
		cur = cur->child[x];
	}
	cur->end = true;
}

void count(string str) {
	node* cur = root;
	for (int i = 0; i < str.size(); i++) {
		int x = str[i] - 'a';
		if (cur->cnt > 1 || i == 0 || cur->end == true) {
			res++;
		}
		cur = cur->child[x];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while (cin >> n) {
		init();
		for (int i = 0; i < n; i++) {
			string str;
			cin >> str;
			v.push_back(str);
			make_trie(str);
		}
		for (int i = 0; i < v.size(); i++) {
			count(v[i]);
		}
		res = res / n;
		cout << fixed;
		cout.precision(2);
		cout << res << '\n';
	}
	return 0;
}
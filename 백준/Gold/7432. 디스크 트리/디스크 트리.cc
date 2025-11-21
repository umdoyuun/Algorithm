#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int n;

class node {
public:
	map<string, node*> child;
};

node* root;

void insert(string str) {
	node* cur = root;
	int pos = 0;

	while (pos < str.length()) {
		int next = str.find('\\', pos);
		if (next == string::npos) {
			next = str.length();
		}

		string tmp = str.substr(pos, next - pos);

		if (cur->child.find(tmp) == cur->child.end()) {
			node* n_node = new node;
			cur->child[tmp] = n_node;
		}
		cur = cur->child[tmp];
		pos = next + 1;
	}
}

void print(node* cur, int d) {
	
	for (auto x : cur->child) {
		for (int i = 0; i < d; i++) {
			cout << ' ';
		}
		cout << x.first << '\n';
		print(x.second, d + 1);
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	root = new node;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		insert(str);
	}
	print(root, 0);
	return 0;
}
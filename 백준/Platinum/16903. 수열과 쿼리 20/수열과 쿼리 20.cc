#include <iostream>
#include <algorithm>
using namespace std;

int n;
struct node {
	int cnt = 0;
	node* child[2] = { nullptr, };
};

node* root;


int check(int x) {
	node* cur = root;
	int ret = 0;
	for (int i = 30; i >= 0; i--) {
		int y = x & (1 << i);
		int f = y ? 1 : 0;
		if (cur->child[!f] && cur->child[!f]->cnt) {
			ret += (1 << i);
			cur = cur->child[!f];
		}
		else {
			cur = cur->child[f];
		}
	}
	return ret;
}

void insert(int x, int t) {
	node* cur = root;
	if(t)
		cur->cnt++;
	for (int i = 30; i >= 0; i--) {
		int y = x & (1 << i);
		if (y) y = 1;
		
		if (cur->child[y] == nullptr) {
			cur->child[y] = new node;
		}
		cur = cur->child[y];
		if(t)
			cur->cnt++;
	}
}

void del(int x) {
	node* cur = root;
	cur->cnt--;
	for (int i = 30; i >= 0; i--) {
		int y = x & (1 << i);
		if (y) y = 1;
		cur = cur->child[y];
		cur->cnt--;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	root = new node;
	insert(0, 1);
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		if (x == 1) {
			insert(y, 1);
		}
		else if (x == 2) {
			del(y);
		}
		else {
			insert(y, 0);
			cout << check(y) << '\n';
		}
	}
	return 0;
}
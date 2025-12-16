#include <iostream>
using namespace std;

class node {
public:
	int cnt;
	node *child[2];
};

node pool[2000000 * 4];
node* root;
int p_cnt;

node* new_node() {
	pool[p_cnt].child[0] = nullptr;
	pool[p_cnt].child[1] = nullptr;
	return &pool[p_cnt++];
}

void insert(int x) {
	node* cur = root;
	for (int i = 22; i >= 0; i--) {
		cur->cnt++;
		int b;
		if (x & (1 << i)) {
			b = 1;
		}
		else {
			b = 0;
		}
		if (cur->child[b] == nullptr) {
			cur->child[b] = new_node();
		}	
		cur = cur->child[b];
	}
	cur->cnt++;
}

int remove(int x) {
	node* cur = root;
	int ret = 0;
	for (int i = 22; i >= 0; i--) {
		cur->cnt--;
		int b;
		if (cur->child[0] && cur->child[1]) {
			if (cur->child[0]->cnt >= x) {
				b = 0;
			}
			else {
				x -= cur->child[0]->cnt;
				b = 1;
			}
		}
		else if (cur->child[0]) {
			b = 0;
		}
		else {
			b = 1;
		}
		ret |= (b << i);
		cur = cur->child[b];
	}
	cur->cnt--;
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	root = new_node();
	for (int i = 0; i < n; i++) {
		int cmd, x;
		cin >> cmd >> x;
		if (cmd == 1) {
			insert(x);
		}
		else {
			int ret = remove(x);
			cout << ret << '\n';
		}
	}
	return 0;
}
#include <iostream>
using namespace std;

int n;
int inorder[100001];
int idx[100001];
int postorder[100001];

void preorder(int in_l, int in_r, int post_l, int post_r) {
	if (in_l > in_r || post_l > post_r) {
		return;
	}
	int root = postorder[post_r];
	int root_idx = idx[root];
	int l_size = root_idx - in_l;
	cout << root << ' ';

	preorder(in_l, root_idx - 1, post_l, post_l + l_size - 1);
	preorder(root_idx + 1, in_r, post_l + l_size, post_r - 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> inorder[i];
		idx[inorder[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> postorder[i];
	}
	preorder(0, n - 1, 0, n - 1);
	return 0;
}
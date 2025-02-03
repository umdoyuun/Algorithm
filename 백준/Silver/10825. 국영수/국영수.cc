#include <iostream>
#include <algorithm>
using namespace std;

int n;
struct score {
	int num, x, y, z;
	string str;
};
score arr[100001];
bool cmp(score a, score b) {
	if (a.x == b.x) {
		if (a.y == b.y) {
			if (a.z == b.z) {
				return a.str < b.str;
			}
			return a.z > b.z;
		}
		return a.y < b.y;
	}
	return a.x > b.x;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		int x, y, z;
		cin >> str >> x >> y >> z;
		arr[i] = { i, x, y, z, str };
	}
	sort(arr, arr + n, cmp);
	for (int i = 0; i < n; i++) {
		cout << arr[i].str << '\n';
	}
	return 0;
}
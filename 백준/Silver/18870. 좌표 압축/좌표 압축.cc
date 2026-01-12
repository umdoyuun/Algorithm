#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v, v2;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	v.reserve(n);
	v2.reserve(n);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
		v2.push_back(x);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (auto x : v2) {
		cout << lower_bound(v.begin(), v.end(), x) - v.begin() << ' ';
	}
	return 0;
}
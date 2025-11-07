#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, res = 0;
	cin >> n >> m;
	vector<int> v;
	v.reserve(n);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	res = n;
	sort(v.begin(), v.end());
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		if(binary_search(v.begin(), v.end(), x)){
			res--;
		}
		else {
			res++;
		}
	}
	cout << res << '\n';
	return 0;
}
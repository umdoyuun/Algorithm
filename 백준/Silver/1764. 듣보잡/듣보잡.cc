#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<string> v;
vector<string> result;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		v.push_back(str);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		if (binary_search(v.begin(), v.end(), str)) {
			result.push_back(str);
		}
	}
	sort(result.begin(), result.end());
	cout << result.size() << '\n';
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << '\n';
	}
	return 0;
}
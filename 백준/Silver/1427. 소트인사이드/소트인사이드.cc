#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;

int main() {
	char c;
	while (cin >> c) {
		v.push_back(-(c - '0'));
	}
	sort(v.begin(), v.end());
	for (auto x : v) {
		cout << -x;
	}
	return 0;
}
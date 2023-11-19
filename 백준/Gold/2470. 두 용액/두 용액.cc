#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Min = 2000000000;

int n;
vector<int> v;
int sum;
int result[2];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	int idx = 0, r_idx = n-1;
	while (idx < r_idx) {
		sum = v[idx] + v[r_idx];
		if (Min > abs(sum)) {
			Min = abs(sum);
			result[0] = v[idx];
			result[1] = v[r_idx];
		}
		if (sum > 0) {
			r_idx--;
		}
		else {
			idx++;
		}
	}
	cout << result[0] << ' ' << result[1] << '\n';
	return 0;
}
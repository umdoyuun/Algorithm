#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int n, res;
int arr[2001];
int zero;
map<int, int> m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if(arr[i] == 0) zero++;
	}
	sort(arr, arr + n);
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			m[arr[i] + arr[j]]++;
		}
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] != 0 && m[arr[i]] > zero) {
			res++;
		}
		else if (arr[i] == 0 && m[arr[i]] >= zero) {
			res++;
		}
	}
	cout << res << '\n';
	return 0;
}
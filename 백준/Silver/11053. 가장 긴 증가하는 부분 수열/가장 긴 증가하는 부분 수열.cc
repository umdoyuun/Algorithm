#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1001];
int dp[1001];
int result;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		int tmp = 0;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				if(tmp < dp[j])
					tmp = dp[j];
			}
		}
		dp[i] = tmp + 1;
		result = max(dp[i], result);
	}
	cout << result;
	return 0;
}
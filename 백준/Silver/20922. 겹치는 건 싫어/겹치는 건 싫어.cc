#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int arr[200001];
int check[200001];
int result;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int left = 0, right = 0;
	for (int i = 0; i < n; i++) {
		check[arr[i]]++;
		if (check[arr[i]] > k) {
			while (1) {
				check[arr[left]]--;
				if (arr[left] == arr[i]) {
					left++;
					break;
				}
				left++;
			}
		}
		int cnt = i - left + 1;
		result = max(cnt, result);
	}
	cout << result;

	return 0;
}
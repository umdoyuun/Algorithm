#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int A[12];
int op[4]; //0:+ 1:- 2:x 3:/
int result_min = 1000000001, result_max = -1000000001;

void func(int sum, int cnt) {
	if (cnt == n) {
		result_min = min(sum, result_min);
		result_max = max(sum, result_max);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (op[i] > 0) {
			op[i]--;
			if (i == 0)
				func(sum + A[cnt], cnt + 1);
			else if (i == 1)
				func(sum - A[cnt], cnt + 1);
			else if (i == 2)
				func(sum * A[cnt], cnt + 1);
			else if (i == 3)
				func(sum / A[cnt], cnt + 1);
			op[i]++;
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}
	func(A[0], 1);
	cout << result_max << '\n' << result_min;
	return 0;
}
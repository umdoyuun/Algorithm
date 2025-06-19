#include <iostream>
#include <map>
using namespace std;

int n, s;
int arr[41];
map<int, int> m;
long long result;


void left_f(int x, int sum) {
	if (x == n / 2) {
		m[sum]++;
		return;
	}
	left_f(x + 1, sum);
	left_f(x + 1, sum + arr[x]);
}

void right_f(int x, int sum) {
	if (x == n) {
		result += m[s - sum];
		return;
	}
	right_f(x + 1, sum);
	right_f(x + 1, sum + arr[x]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	left_f(0, 0);
	right_f(n / 2, 0);
	if (s == 0) result--;
	cout << result;
}
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int map[15];
int n, result = 0;

bool check(int x) {
	for (int i = 0; i < x; i++) {
		if (map[i] == map[x]) return false;
		if(abs(map[x] - map[i]) == abs(x-i)) return false;
	}
	return true;
}

void func(int idx) {
	if (idx == n) {
		result++;
		return;
	}
	for (int i = 0; i < n; i++) {
		map[idx] = i;
		if (check(idx)) func(idx + 1);
	}
}

int main() {
	cin >> n;
	func(0);
	cout << result;
	return 0;
}
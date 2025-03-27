#include <iostream>
using namespace std;

bool visit[10001];

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);

	for (int i = 1; i <= 10000; i++) {
		int tmp = i;
		int x = i;
		while (tmp) {
			x += tmp % 10;
			tmp /= 10;
		}
		if (x <= 10000) 
			visit[x] = true;
	}
	for (int i = 1; i <= 10000; i++) {
		if (!visit[i]) cout << i << '\n';
	}
	return 0;
}
#include <iostream>
using namespace std;

long long a, b;
int res;
bool visit[10000001];

void eratostenes() {
	for (register int i = 2; i < 10000001; i++) {
		if (!visit[i]) {
			for (register int j = i + i; j < 10000001; j += i) {
				visit[j] = true;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> a >> b;
	eratostenes();
	for (long long i = 2; i * i <= b; i++) {
		if (visit[i]) continue;
		for (long long j = i * i; j <= b; j *= i) {
			if (a <= j) {
				res++;
			}
			if (j > b / i) break;
		}
	}
	cout << res << '\n';
	return 0;
}
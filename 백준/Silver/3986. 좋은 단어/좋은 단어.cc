#include <iostream>
using namespace std;

char stack[100001];
int t, res; //  t: top

void init() {
	t = -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	while (n--) {
		init();
		string str;
		cin >> str;
		for (char c : str) {
			if (t >= 0 && c == stack[t]) {
				t--;
				while (t >= 1) {
					if (stack[t] == stack[t - 1]) {
						t = t - 2;
					}
					else {
						break;
					}
				}
			}
			else {
				stack[++t] = c;
			}
		}
		if (t == -1) res++;
	}
	cout << res << '\n';
	return 0;
}
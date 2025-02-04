#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int s[1000001] = { 0, };
	int n, cmd, x, e = 0;
	cin >> n;
	while (n--) {
		cin >> cmd;
		switch (cmd) {
		case 1: 
			cin >> x;
			s[e++] = x;
			break;
		case 2:
			if (e) {
				cout << s[e - 1] << '\n';
				e--;
			}
			else cout << "-1\n";
			break;
		case 3:
			cout << e << '\n';
			break;
		case 4:
			if (!e) cout << "1\n";
			else cout << "0\n";
			break;
		case 5:
			if (e) {
				cout << s[e - 1] << '\n';
			}
			else cout << "-1\n";
		}
	}
	return 0;
}
#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	stack<int> s;
	int n, cmd, x;
	cin >> n;
	while (n--) {
		cin >> cmd;
		switch (cmd) {
		case 1: 
			cin >> x;
			s.push(x);
			break;
		case 2:
			if (!s.empty()) {
				cout << s.top() << '\n';
				s.pop();
			}
			else cout << "-1\n";
			break;
		case 3:
			cout << s.size() << '\n';
			break;
		case 4:
			if (s.empty()) cout << "1\n";
			else cout << "0\n";
			break;
		case 5:
			if (!s.empty()) {
				cout << s.top() << '\n';
			}
			else cout << "-1\n";
		}
	}
	return 0;
}
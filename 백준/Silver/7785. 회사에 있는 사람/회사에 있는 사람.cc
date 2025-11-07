#include <iostream>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	set<string> s;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str, cmd;
		cin >> str >> cmd;
		if (cmd[0] == 'e') {
			s.insert(str);
		}
		else {
			s.erase(str);
		}
	}
	for (auto it = s.rbegin(); it != s.rend(); it++) {
		cout << *it << '\n';
	}
	return 0;
}
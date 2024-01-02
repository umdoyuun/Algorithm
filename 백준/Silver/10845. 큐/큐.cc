#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n;
queue<int> q;

void func(string cmd) {
	if (cmd == "push") {
		int x;
		cin >> x;
		q.push(x);
	}
	else if (cmd == "empty") {
		cout << q.empty() << '\n';
	}
	else if (cmd == "size") {
		cout << q.size() << '\n';
	}
	else {
		if (q.empty()) cout << "-1\n";
		else if (cmd == "pop") {
			cout << q.front() << '\n';
			q.pop();
		}
		else if (cmd == "front") {
			cout << q.front() << '\n';
		}
		else if (cmd == "back") {
			cout << q.back() << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		func(str);
	}
	return 0;
}
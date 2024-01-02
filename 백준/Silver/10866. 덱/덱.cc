#include <iostream>
#include <deque>
#include <string>
using namespace std;

int n;
deque<int> dq;

void func(string cmd) {
	if (cmd == "push_front") {
		int x;
		cin >> x;
		dq.push_front(x);
	}
	else if (cmd == "push_back") {
		int x;
		cin >> x;
		dq.push_back(x);
	}
	else if (cmd == "pop_front") {
		if (dq.empty()) cout << "-1\n";
		else {
			cout << dq.front() << '\n';
			dq.pop_front();
		}
	}
	else if (cmd == "pop_back") {
		if (dq.empty())cout << "-1\n";
		else {
			cout << dq.back() << '\n';
			dq.pop_back();
		}
	}
	else if (cmd == "size") {
		cout << dq.size() << '\n';
	}
	else if (cmd == "empty") {
		cout << dq.empty() << '\n';
	}
	else if (cmd == "front") {
		if (dq.empty()) cout << "-1\n";
		else cout << dq.front() << '\n';
	}
	else if (cmd == "back") {
		if (dq.empty()) cout << "-1\n";
		else cout << dq.back() << '\n';
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
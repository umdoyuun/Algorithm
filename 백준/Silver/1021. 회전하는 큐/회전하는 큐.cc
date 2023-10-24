#include <iostream>
#include <deque>
using namespace std;

int n, m;
deque<int> dq;
int result;

void func(int goal) {
	int left = 0, right = 0;
	for (int i = 0; i < dq.size(); i++) {
		if (dq[i] == goal) {
			left = i;
			right = dq.size() - i;
			break;
		}
	}
	if (left > right) {
		result++;
		while (true) {
			if (dq.back() == goal)
				break;
			dq.push_front(dq.back());
			dq.pop_back();
			result++;
		}
		dq.pop_back();
	}
	else {
		while (true) {
			if (dq.front() == goal)
				break;
			dq.push_back(dq.front());
			dq.pop_front();
			result++;
		}
		dq.pop_front();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		dq.push_back(i);
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		func(x);
	}
	cout << result;
	return 0;
}
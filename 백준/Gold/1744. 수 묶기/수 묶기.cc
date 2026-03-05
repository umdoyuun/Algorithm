#include <iostream>
#include <queue>
using namespace std;

int n, res;
priority_queue<int> mxh, mnh;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int x, y;
	for (int i = 0; i < n; i++) {		
		cin >> x;
		if (x == 1) res += 1;
		else if (x > 1) mxh.push(x);
		else mnh.push(-x);
	}
	while (!mxh.empty()) {
		x = mxh.top();
		mxh.pop();
		if (mxh.empty()) {
			res += x;
			break;
		}
		y = mxh.top();
		mxh.pop();
		res += x * y;
	}
	while (!mnh.empty()) {
		x = mnh.top();
		mnh.pop();
		if (mnh.empty()) {
			res -= x;
			break;
		}
		y = mnh.top();
		mnh.pop();
		res += x * y;
	}
	cout << res << '\n';
	return 0;
}
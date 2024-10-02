#include <iostream>
#include <deque>
using namespace std;

int n;
long long res;
deque<int> dq;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		
		while (!dq.empty()) {
			if (dq.back() <= x) dq.pop_back();
			else break;
		}
		res += dq.size();
		dq.push_back(x);
	}
	cout << res << '\n';
	return 0;
}
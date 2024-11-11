#include <iostream>
#include <stack>
using namespace std;

int n;
long long res;
stack<pair<int, int>> s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		while (!s.empty() && s.top().first < x) {
			res += s.top().second;
			s.pop();
		}
		if (s.empty()) {
			s.push({ x, 1 });
			continue;
		}
		
		if (s.top().first == x) {
			res += s.top().second;
			s.top().second++;
			if (s.size() > 1) res++;
		}
		else {
			res++;
			s.push({ x, 1 });
		}
	}
	cout << res;
	return 0;
}
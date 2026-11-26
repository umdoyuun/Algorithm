#include <iostream>
#include <list>
using namespace std;

int n;
list<pair<int, int>> li;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		li.push_back({ x, i });
	}
	auto it = li.begin();
	int cnt = 0;
	while (true) {
		cout << it->second + 1 << ' ';
		int mv = it->first;
		it = li.erase(it);
		if (li.empty()) break;
		if (it == li.end()) it = li.begin();

		if (mv > 0) {
			for (int k = 0; k < mv - 1; k++) {
				++it;
				if (it == li.end()) it = li.begin();
			}
		}
		else {
			for (int k = 0; k < -mv; k++) {
				if (it == li.begin()) it = li.end();
				--it;
			}
		}
	}
	return 0;
}
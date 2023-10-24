#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		pq.push({ x,y });
	}
	for (int i = 0; i < n; i++) {
		cout << pq.top().first << ' ' << pq.top().second << '\n';
		pq.pop();
	}
	return 0;
}
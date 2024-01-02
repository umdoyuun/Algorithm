#include <iostream>
#include <queue>
using namespace std;

struct node {
	int x, weight;
};
int n, target;
queue<node> q;
priority_queue<int> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int result = 0;
		cin >> n >> target;
		for (int i = 0; i < n; i++) {
			int w;
			cin >> w;
			q.push({ i, w });
			pq.push(w);
		}
		while(!q.empty()){
			if (q.front().weight == pq.top()) {
				result++;
				if (q.front().x == target) {
					cout << result << '\n';
				}
				q.pop();
				pq.pop();
			}
			else {
				q.push({ q.front().x, q.front().weight });
				q.pop();
			}
		}
	}
	return 0;
}
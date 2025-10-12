#include <iostream>
#include <queue>
using namespace std;

int n;
priority_queue<int> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int x;
	for (register int i = 0; i < n * n; i++) {
		cin >> x;
		if(pq.size() < n){
			pq.push(-x);
		}
		else if (-x < pq.top()) {
			pq.pop();
			pq.push(-x);
		}
		
	}
	cout << -pq.top() << '\n';
	return 0;
}
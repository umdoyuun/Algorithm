#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, cnt;
vector<pair<int, int>> arr;
vector<int> res;

class pc {
public:
	int et, num;
	bool operator < (const pc& other) const {
		return et > other.et;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	arr.reserve(n);
	res.reserve(n / 2);
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		arr.push_back({ x, y });
	}
	sort(arr.begin(), arr.end());
	priority_queue<pc> pq;
	priority_queue<int> pc_use;
	for (auto cur : arr) {
		while (!pq.empty()) {
			if (pq.top().et < cur.first) {
				pc_use.push(-pq.top().num);
				pq.pop();
			}
			else {
				break;
			}
		}
		int pn;
		if (pc_use.empty()) {
			pn = cnt++;
			res.push_back(1);
		}
		else {
			pn = -pc_use.top();			
			res[pn]++;
			pc_use.pop();
		}
		pq.push({ cur.second, pn });
	}
	cout << cnt << '\n';
	for (int r : res) {
		cout << r << ' ';
	}
	return 0;
}
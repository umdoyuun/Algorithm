#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct node {
	int w, cost;
};
int n, k;
vector<node> v;
vector<int> bags;
long long result;

bool compare(node x, node y) {
	return x.w < y.w;
}

void func() {
	priority_queue<int, vector<int>, less<>>pq;
	int idx = 0;
	for (int i = 0; i < k; i++) {
		int bag_w = bags[i];
		while (true) {
			if (idx >= n) break;
			if (v[idx].w > bag_w) break;
			pq.push(v[idx++].cost);
		}
		if (pq.empty()) continue;
		result += pq.top();
		pq.pop();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int w, c;
		cin >> w >> c;
		v.push_back({ w,c });
	}
	for (int i = 0; i < k; i++) {
		int w;
		cin >> w;
		bags.push_back(w);
	}
	sort(v.begin(), v.end(), compare);
	sort(bags.begin(), bags.end());
	func();
	cout << result;
	return 0;
}
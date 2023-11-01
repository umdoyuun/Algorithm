#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct node {
	int x, y;
};

vector<node> v;
int n, result;

bool compare(node a, node b) {
	return a.x < b.x;
}

void init() {
	v.clear();
	result = 0;
}

void print() {
	cout << '\n';
	for (int i = 0; i < n; i++) {
		cout << v[i].x << ' ' << v[i].y << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		init();
		cin >> n;
		int x, y;
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			v.push_back({ x,y });
		}
		sort(v.begin(), v.end(), compare);
		//print();

		int max_score = v[0].y;
		for (int i = 0; i < n; i++) {
			int x = v[i].y;
			if (max_score >= x) {
				result++;
				max_score = v[i].y;
			}
		}
		cout << result << '\n';
	}
	return 0;
}
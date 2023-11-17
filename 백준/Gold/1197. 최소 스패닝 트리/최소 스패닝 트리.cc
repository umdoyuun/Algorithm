#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
	int x, y, cost;
};
int v, e, result;
vector<node> V;
int parent[10001];

bool compare(node x, node y) {
	return x.cost < y.cost;
}

int getParent(int x) {
	if (x == parent[x]) return x;
	else return parent[x] = getParent(parent[x]);
}

bool unionParent(int x, int y) {
	x = getParent(x);
	y = getParent(y);
	if (x == y) return false;
	parent[x] = y;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> v >> e;
	for (int i = 1; i <= v; i++)
		parent[i] = i;
	for (int i = 0; i < e; i++) {
		int x, y, cost;
		cin >> x >> y >> cost;
		V.push_back({ x, y, cost });
	}
	sort(V.begin(), V.end(), compare);
	for (int i = 0; i < V.size(); i++) {
		if (unionParent(V[i].x, V[i].y))
			result += V[i].cost;
	}
	cout << result;
	return 0;
}
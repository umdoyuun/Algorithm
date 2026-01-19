#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int A, B, C;
bool visit[201][201][201];
vector<int> res;

void dfs(int a, int b, int c) {
	if (visit[a][b][c]) return;
	visit[a][b][c] = true;
	if (a == 0) {
		res.push_back(c);
	}

	// A -> B
	int move = min(a, B - b);
	dfs(a - move, b + move, c);

	// A -> C
	move = min(a, C - c);
	dfs(a - move, b, c + move);

	// B -> A
	move = min(b, A - a);
	dfs(a + move, b - move, c);

	// B -> C
	move = min(b, C - c);
	dfs(a, b - move, c + move);

	// C -> A
	move = min(c, A - a);
	dfs(a + move, b, c - move);

	// C -> B
	move = min(c, B - b);
	dfs(a, b + move, c - move);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> A >> B >> C;
	dfs(0, 0, C);

	sort(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end()), res.end());

	for (int x : res) {
		cout << x << " ";
	}

	return 0;
}
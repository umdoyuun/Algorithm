#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct XY {
	int x, y;
};

int n, m, result = 987654321;
int map[51][51];
int visit[13];

vector<XY> H, C, v;

int find_dist() {
	int sum = 0;
	for (int i = 0; i < H.size(); i++) {
		int x = H[i].x;
		int y = H[i].y;
		int dist = 987654321;
		for (int j = 0; j < v.size(); j++) {
			int nx = v[j].x;
			int ny = v[j].y;
			int d = abs(x - nx) + abs(y - ny);
			dist = min(dist, d);
		}
		sum += dist;
	}
	return sum;
}

void func(int idx, int cnt) {
	if (cnt == m) {
		result = min(result, find_dist());
		return;
	}
	for (int i = idx; i < C.size(); i++) {
		if (visit[i]) continue;
		visit[i] = true;
		v.push_back(C[i]);
		func(i, cnt + 1);
		visit[i] = false;
		v.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) H.push_back({ i,j });
			if (map[i][j] == 2) C.push_back({ i,j });
		}
	}
	func(0, 0);
	cout << result;
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int graph[21][21];
int result = 2;



int q[1000];

void shift(int type) { // 0:상 1:하 2:좌 3:우
	int s = 0, e = 0;
	//queue<int> q;
	int idx;
	switch (type) {
	case 0:
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < n; i++) {
				if (graph[i][j] != 0) {
					//q.push(graph[i][j]);
					q[e++] = graph[i][j];
					graph[i][j] = 0;
				}
			}
			idx = 0;
			while (s != e) {
				int x = q[s++];
				//q.pop();
				if (graph[idx][j] == 0) {
					graph[idx][j] = x;
				}
				else if (graph[idx][j] == x) {
					graph[idx][j] *= 2;
					idx++;
				}
				else {
					idx++;
					graph[idx][j] = x;
				}
			}
		}
		break;
	case 1:
		for (int j = 0; j < n; j++) {
			for (int i = n - 1; i >= 0; i--) {
				if (graph[i][j] != 0) {
					//q.push(graph[i][j]);
					q[e++] = graph[i][j];
					graph[i][j] = 0;
				}
			}
			idx = n - 1;
			while (s != e) {
				int x = q[s++];
				//q.pop();
				if (graph[idx][j] == 0) {
					graph[idx][j] = x;
				}
				else if (graph[idx][j] == x) {
					graph[idx][j] *= 2;
					idx--;
				}
				else {
					idx--;
					graph[idx][j] = x;
				}
			}
		}
		break;
	case 2:
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (graph[i][j] != 0) {
					//q.push(graph[i][j]);
					q[e++] = graph[i][j];
					graph[i][j] = 0;
				}
			}
			idx = 0;
			while (s != e) {
				int x = q[s++];
				//q.pop();
				if (graph[i][idx] == 0) {
					graph[i][idx] = x;
				}
				else if (graph[i][idx] == x) {
					graph[i][idx] *= 2;
					idx++;
				}
				else {
					idx++;
					graph[i][idx] = x;
				}
			}
		}
		break;
	case 3:
		for (int i = 0; i < n; i++) {
			for (int j = n - 1; j >= 0; j--) {
				if (graph[i][j] != 0) {
					//q.push(graph[i][j]);
					q[e++] = graph[i][j];
					graph[i][j] = 0;
				}
			}
			idx = n - 1;
			while (s != e) {
				int x = q[s++];
				//q.pop();
				if (graph[i][idx] == 0) {
					graph[i][idx] = x;
				}
				else if (graph[i][idx] == x) {
					graph[i][idx] *= 2;
					idx--;
				}
				else {
					idx--;
					graph[i][idx] = x;
				}
			}
		}
	}
}

void get_max() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			result = max(result, graph[i][j]);
		}
	}
}

void dfs(int cnt) {
	if (cnt == 5) {
		get_max();
		return;
	}
	int c_graph[21][21];
	int mx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			c_graph[i][j] = graph[i][j];
			mx = max(mx, graph[i][j]);
		}
	}
	if ((mx << (5 - cnt)) <= result) return;
	for (int i = 0; i < 4; i++) {
		shift(i);
		dfs(cnt + 1);
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				graph[j][k] = c_graph[j][k];
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}
	dfs(0);
	cout << result;
	return 0;
}
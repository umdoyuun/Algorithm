#include <iostream>
#include <queue>
using namespace std;

int w, h, T;
char board[1001][1001];
int visited_fire[1001][1001];
int visited_sangeun[1001][1001];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
queue<pair<int, int>> Q_fire, Q_sangeun;

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;

	for (int i = 0; i < T; i++) {
		int isrun = 0;
		Q_fire = queue<pair<int, int>>();
        Q_sangeun = queue<pair<int, int>>();
		cin >> w >> h;

		for (int j = 0; j < h; j++) {
			fill(board[j], board[j] + w, 0);
			fill(visited_fire[j], visited_fire[j] + w, -1);
			fill(visited_sangeun[j], visited_sangeun[j] + w, -1);
		}

		for (int j = 0; j < h; j++) {
			for (int k = 0; k < w; k++) {
				cin >> board[j][k];
				if (board[j][k] == '*') {
					Q_fire.push({ j, k });
					visited_fire[j][k] = 0;
				}
				else if (board[j][k] == '@') {
					Q_sangeun.push({ j, k });
					visited_sangeun[j][k] = 0;
				}
			}
		}

		// 불의 소요시간 먼저 계산
		while (!Q_fire.empty()) {
			int x = Q_fire.front().first;
			int y = Q_fire.front().second;
			Q_fire.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
				if (board[nx][ny] != '#' && visited_fire[nx][ny] == -1) {
					Q_fire.push({ nx, ny });
					visited_fire[nx][ny] = visited_fire[x][y] + 1;
				}
			}
		}

		// 상근이 탈출시간 계산
		while (!Q_sangeun.empty()) {
			int x = Q_sangeun.front().first;
			int y = Q_sangeun.front().second;
			Q_sangeun.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				// 탈출 성공
				if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
					cout << visited_sangeun[x][y] + 1 << "\n";
					isrun = 1;
					break;
				}

				if (board[nx][ny] != '#' && visited_sangeun[nx][ny] == -1 && (visited_fire[nx][ny] == -1 || visited_sangeun[x][y] + 1 < visited_fire[nx][ny])) { 
                    Q_sangeun.push({ nx, ny });
					visited_sangeun[nx][ny] = visited_sangeun[x][y] + 1;
				}
			}
			if (isrun == 1) break;
		}

		// 탈출 실패
		if(isrun == 0) cout << "IMPOSSIBLE\n";
	}
}
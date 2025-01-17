#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, res;
char arr[101][101];
int row[101][101];
int col[101][101];
vector<int> v[10001];
bool visit[10001];
int d[10001];
int row_cnt, col_cnt;

bool dfs(int x) {
    if (visit[x]) return false;
    visit[x] = true;

    for (int y : v[x]) {
        if (d[y] == 0 || dfs(d[y])) {
            d[y] = x;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    row_cnt = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] == '.') {
                row[i][j] = row_cnt;
                if (j == n || arr[i][j + 1] == 'X') row_cnt++;
            }
        }
    }

    col_cnt = 1;
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= n; i++) {
            if (arr[i][j] == '.') {
                col[i][j] = col_cnt;
                if (i == n || arr[i + 1][j] == 'X') col_cnt++;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] == '.') {
                v[row[i][j]].push_back(col[i][j]);
            }
        }
    }

    for (int i = 1; i < row_cnt; i++) {
        memset(visit, false, sizeof(visit));
        if (dfs(i)) res++;
    }

    cout << res << '\n';
    return 0;
}
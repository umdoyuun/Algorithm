#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, n, cnt;
vector<int> v[501];
int d[501];
bool visit[501];

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

bool dfs(int x) {
    if (visit[x]) return false;
    visit[x] = true;
    for (int y : v[x]) {
        if (d[y] == -1 || dfs(d[y])) {
            d[y] = x;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    while (true) {
        cin >> m >> n;
        if (m == 0 && n == 0) break;
        
        vector<int> blue(m), red(n);
        
        for (int i = 0; i < m; i++) {
            cin >> blue[i];
            v[i].clear();
        }
        
        for (int i = 0; i < n; i++) {
            cin >> red[i];
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (gcd(blue[i], red[j]) > 1) {
                    v[i].push_back(j);
                }
            }
        }
        
        fill(d, d + n, -1);
        cnt = 0;
        
        for (int i = 0; i < m; i++) {
            fill(visit, visit + m, false);
            if (dfs(i)) cnt++;
        }
        
        cout << cnt << '\n';
    }
    
    return 0;
}
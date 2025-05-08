#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstring>
using namespace std;

int n, m;
string strs[51];
vector<pair<int, int>> towns;
vector<string> townNames;
vector<pair<int, int>> namePositions[2501]; 
vector<int> adj[2501];
int matched[2501];
bool visited[2501];

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool dfs(int node) {
    if (visited[node]) return false;
    visited[node] = true;
    
    for (int next : adj[node]) {
        if (matched[next] == -1 || dfs(matched[next])) {
            matched[next] = node;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (strs[i][j] == 'x') {
                towns.push_back({i, j});
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        string name = "";
        for (int j = 0; j < m; j++) {
            if (strs[i][j] >= 'A' && strs[i][j] <= 'Z') {
                name += strs[i][j];
            } else if (!name.empty()) {
                townNames.push_back(name);
                
                // 이름의 각 문자 위치 저장
                int nameIndex = townNames.size() - 1;
                for (int k = 0; k < name.length(); k++) {
                    namePositions[nameIndex].push_back({i, j - name.length() + k});
                }
                name = "";
            }
        }
        if (!name.empty()) {
            townNames.push_back(name);
            int nameIndex = townNames.size() - 1;
            for (int k = 0; k < name.length(); k++) {
                namePositions[nameIndex].push_back({i, m - name.length() + k});
            }
        }
    }
    
    // 마을과 이름 연결
    for (int i = 0; i < towns.size(); i++) {
        int tx = towns[i].first;
        int ty = towns[i].second;
        
        for (int j = 0; j < townNames.size(); j++) {
            bool adjacent = false;
            
            // 마을 주변 8방향 검사
            for (int d = 0; d < 8; d++) {
                int nx = tx + dx[d];
                int ny = ty + dy[d];
                
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                
                for (auto& pos : namePositions[j]) {
                    if (pos.first == nx && pos.second == ny) {
                        adjacent = true;
                        break;
                    }
                }
                if (adjacent) break;
            }
            
            if (adjacent) {
                adj[i].push_back(j);
            }
        }
    }
    
    memset(matched, -1, sizeof(matched));
    for (int i = 0; i < towns.size(); i++) {
        memset(visited, false, sizeof(visited));
        dfs(i);
    }
    
    for (int i = 0; i < towns.size(); i++) {
        int matchedName = -1;
        for (int j = 0; j < townNames.size(); j++) {
            if (matched[j] == i) {
                matchedName = j;
                break;
            }
        }
        
        if (matchedName != -1) {
            cout << towns[i].first + 1 << " " << towns[i].second + 1 << " " << townNames[matchedName] << "\n";
        }
    }
    
    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

vector<vector<int>> adj;
vector<int> match;
vector<bool> visited;

bool dfs(int x) {
    if (visited[x]) return false;
    visited[x] = true;
    
    for (int y : adj[x]) {
        if (match[y] == -1 || dfs(match[y])) {
            match[y] = x;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    
    while (t--) {
        int c, d, v;
        cin >> c >> d >> v;
        
        vector<pair<int, int>> catVotes, dogVotes;
        
        for (int i = 0; i < v; i++) {
            string advance, eliminate;
            cin >> advance >> eliminate;
            
            int advance_id, eliminate_id;
            
            if (advance[0] == 'C') {
                advance_id = stoi(advance.substr(1));
            } else {
                advance_id = stoi(advance.substr(1));
            }
            
            if (eliminate[0] == 'C') {
                eliminate_id = stoi(eliminate.substr(1));
            } else {
                eliminate_id = stoi(eliminate.substr(1));
            }
            
            if (advance[0] == 'C') {
                catVotes.push_back({advance_id, eliminate_id});
            } else {
                dogVotes.push_back({advance_id, eliminate_id});
            }
        }
        
        adj.clear();
        adj.resize(catVotes.size());
        
        for (int i = 0; i < catVotes.size(); i++) {
            for (int j = 0; j < dogVotes.size(); j++) {
                
                bool conflict = false;
                
                if (catVotes[i].first == dogVotes[j].second) {
                    conflict = true;
                }
                
                if (catVotes[i].second == dogVotes[j].first) {
                    conflict = true;
                }
                
                if (conflict) {
                    adj[i].push_back(j);
                }
            }
        }
        
        match.assign(dogVotes.size(), -1);
        int matching = 0;
        
        for (int i = 0; i < catVotes.size(); i++) {
            visited.assign(catVotes.size(), false);
            if (dfs(i)) {
                matching++;
            }
        }
        
        cout << v - matching << '\n';
    }
    
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, s, l;
vector<int> v[100001];
int order[100001];

void dfs(int x){
    order[x] = ++l;
    for(int y : v[x]){
        if(order[y]) continue;
        dfs(y);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> s;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i = 1; i <= n; i++){
        sort(v[i].begin(), v[i].end(), greater<int>());
    }
    dfs(s);
    for(int i = 1; i<= n; i++){
        cout << order[i] << '\n';
    }
    return 0;
}
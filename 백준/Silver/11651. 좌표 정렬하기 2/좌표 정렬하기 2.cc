#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define pii pair<int, int>

int n;
vector<pii> v;

bool cmp(pii a, pii b){
    if(a.second == b.second) return a.first < b.first;
    else return a.second < b.second;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end(), cmp);
    for(pii x : v){
        cout << x.first << ' ' << x.second << '\n';
    }
    return 0;
}
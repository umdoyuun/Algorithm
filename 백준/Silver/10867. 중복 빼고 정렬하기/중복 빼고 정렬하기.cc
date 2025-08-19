#include <iostream>
#include <map>
using namespace std;

int n;
map<int, bool> m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        m[x] = true;
    }
    for(auto x : m){
        cout << x.first << ' ';
    }
    return 0;
}
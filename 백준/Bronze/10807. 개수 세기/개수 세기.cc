#include <iostream>
using namespace std;

int cnt[205];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        cnt[x + 100]++;
    }
    int v;
    cin >> v;
    cout << cnt[v + 100] << '\n';
    return 0;
}
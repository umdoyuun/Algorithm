#include <iostream>
using namespace std;

int cnt[10001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    register int n, x;
    cin >> n;
    while(n--){
        cin >> x;
        cnt[x]++;
    }
    for(int i = 1; i <= 10000; i++){
        for(int j = 0; j < cnt[i]; j++){
            cout << i << '\n';
        }
    }
    return 0;
}
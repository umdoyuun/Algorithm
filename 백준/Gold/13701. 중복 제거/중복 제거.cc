#include <iostream>
#include <bitset>
using namespace std;

bitset<33554432> b;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x;
    while(cin >> x){
        if(b[x]) continue;
        b[x] = 1;
        cout << x << ' ';
    }
    return 0;
}
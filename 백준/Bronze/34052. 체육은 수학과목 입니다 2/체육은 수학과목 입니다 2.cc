#include <iostream>
using namespace std;

int main(){
    int x, res = 0;
    for(int i = 0; i < 4; i++){
        cin >> x;
        res += x;
    }
    if(res <= 1500) cout << "Yes\n";
    else cout << "No\n";
}
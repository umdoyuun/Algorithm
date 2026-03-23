#include <iostream>
using namespace std;

int coin[4] = {25, 10, 5, 1};

int main(){
    int T, c;
    cin >> T;
    while(T--){
        cin >> c;
        for(int i = 0; i < 4; i++ ){
            if(i == 3) cout << c / coin[i];
            else cout << c / coin[i] << ' ';
            c %= coin[i];
        }
        cout << '\n';
    }
}
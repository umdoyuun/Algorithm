#include <iostream>
using namespace std;

int main(){
    int res = -1, rx, ry;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            int x;
            cin >> x;
            if(x > res){
                res = x;
                rx = i + 1;
                ry = j + 1;
            }
        }
    }
    cout << res << '\n' << rx << ' ' << ry <<'\n';
    return 0;
}
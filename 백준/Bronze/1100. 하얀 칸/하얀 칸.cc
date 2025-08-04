#include <iostream>
using namespace std;

int main(){
    int res = 0;
    char c;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cin >> c;
            if(c == 'F' && !((i + j) % 2)) res++;
        }
            
    }
    cout << res << '\n';
    return 0;
}
#include <iostream>
using namespace std;

int main(){
    int res = 0;
    for(int i = 0; i < 5; i++){
        int x;
        cin >> x;
        res += x;
    }
    cout << res << '\n';
    return 0;
}
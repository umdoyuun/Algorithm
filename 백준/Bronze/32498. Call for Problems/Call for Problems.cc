#include <iostream>
using namespace std;

int main(){
    int n, x, res = 0;
    cin >> n;
    while(n--){
        cin >> x;
        if(x % 2) res++;
    }
    cout << res << '\n';
    return 0;
}
#include <iostream>
using namespace std;

int main(){
    int n, res = 0, x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        res += x;
    }
    cout << res;
}
#include <iostream>
using namespace std;

int main(){
    int res = 0, tar;
    cin >> tar;
    for(int i = 0; i < 5; i++){
        int x;
        cin >> x;
        if(x == tar) res++;
    }
    cout << res;
}
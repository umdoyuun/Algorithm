#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n <= 1) cout << 1;
    else if(n == 2) cout << 2;
    else if(n == 3) cout << 6;
    else if(n == 4) cout << 4;
    else cout << 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    long long x, y;
    cin >> x >> y;
    if(!(x % 2) || !(y % 2)) {
        cout << 0 << '\n';
    }
    else {
        cout << min(x, y) << '\n';
    }
}
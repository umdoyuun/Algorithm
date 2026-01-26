#include <iostream>
using namespace std;

int main(){
    int x, y;
    cin >> x >> y;
    if(y > x) cout << y - x << '\n';
    else cout << x + y << '\n';
    return 0;
}
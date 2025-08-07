#include <iostream>
using namespace std;

int main(){
    int x;
    cin >> x;
    if((x - 2) % 7) cout << 0 << '\n';
    else cout << 1 << '\n';
    return 0;
}
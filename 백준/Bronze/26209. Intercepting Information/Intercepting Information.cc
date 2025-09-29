#include <iostream>
using namespace std;

int main() {
    bool res = false;
    for (int i = 0; i < 8; i++) {
        int x; 
        cin >> x;
        if (x == 9) res = true;
    }
    if (res) cout << "F\n";
    else cout << "S\n";
}
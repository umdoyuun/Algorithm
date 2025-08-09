#include <iostream>
using namespace std;

int main(){
    double x, y;
    cin >> x >> y;
    cout << fixed;
    cout.precision(1);
    cout << x * y / 2;
    return 0;
}
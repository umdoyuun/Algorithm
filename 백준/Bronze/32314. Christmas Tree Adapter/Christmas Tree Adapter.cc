#include <iostream>
using namespace std;

int a;
double w, v;

int main() {
    cin >> a >> w >> v;
    cout << (w / v >= a ? 1 : 0) << '\n';
    return 0;
}
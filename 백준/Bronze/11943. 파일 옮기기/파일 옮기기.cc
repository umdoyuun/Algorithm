#include <iostream>
using namespace std;

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int res = a + d < b + c ? a + d : b + c;
    cout << res;
}
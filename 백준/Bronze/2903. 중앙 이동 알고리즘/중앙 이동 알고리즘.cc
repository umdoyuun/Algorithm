#include <iostream>
#include <cmath>
using namespace std;

int main()
{  
    int n, res=2;
    cin >> n;
    for(int i = 1; i <= n; i++) res += (res - 1);
    res = pow(res, 2);
    cout << res;
    return 0;
}
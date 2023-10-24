#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, l;
    cin >> n >> l;
    for (int m = l; m <= 100; m++) {
        int tmp = n - m * (m+1) / 2;
        if (tmp % m == 0) {
            int x = tmp / m + 1;
            if (x >= 0) {
                for (int i = 0; i < m; i++) {
                    cout << x + i << ' ';
                }
                return 0;
            }
        }
        
    }
    cout << "-1\n";
    return 0;
}
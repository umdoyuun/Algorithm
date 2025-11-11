#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    long long x, y;
    cin >> x >> y;
    if (x > y) swap(x, y);
    long long e = x * y;
    long long ret = 0;
    for (long long i = y; i <= e; i += y) {
        if (i % x == 0) {
            ret = i;
            break;
        }
    }
    cout << ret << '\n';
	return 0;	
}
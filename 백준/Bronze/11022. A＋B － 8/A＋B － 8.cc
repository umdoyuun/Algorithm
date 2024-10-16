//Case #x: A + B = C
#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        cout << "Case #" << i << ": " << x << " + " << y <<" = " << x+y <<'\n';
    }
    return 0;
}
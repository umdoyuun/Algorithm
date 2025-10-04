#include <iostream>
using namespace std;

int main(){
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
        int x, y;
        cin >> x >> y;
        cout << "Case " << tc << ": " << x + y << '\n';
    }
}
#include <iostream>
using namespace std;

int n, res;
int map[1000][1000];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        for(int i = x; i < x + 10; i++){
            for(int j = y; j < y + 10; j++){
                if(map[i][j]) continue;
                map[i][j] = 1;
                res++;
            }
        }
    }
    cout << res << '\n';
    return 0;
}
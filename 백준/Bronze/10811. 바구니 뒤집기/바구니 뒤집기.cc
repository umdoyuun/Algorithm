#include <iostream>
using namespace std;

int arr[101];

int main(){
    int n, m;
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        arr[i] = i;
    }
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        if(x > y) swap(x, y);
        for(int j = 0; j <= (y - x) / 2; j++){
            swap(arr[x + j], arr[y - j]);
        }
    }
    for(int i = 1; i <= n; i++){
        cout << arr[i] << ' ';
    }
}
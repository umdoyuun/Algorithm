#include <iostream>
using namespace std;

int arr[4], x, y, r, ans;

int main(){
    for(int i = 0; i < 4; i++){
        cin >> arr[i];
    }
    cin >> x >> y >> r;
    for(int i = 0; i < 4; i++){
        if(x == arr[i]) ans = i + 1;
    }
    cout << ans;
}
#include <iostream>
using namespace std;

int main(){
    int n, sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        sum += x;
    }
    if(sum > 0) cout << "Right";
    else if(sum < 0) cout << "Left";
    else cout << "Stay";
}
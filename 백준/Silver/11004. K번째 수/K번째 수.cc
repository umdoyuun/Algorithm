#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[5000001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    cout << arr[m - 1] << '\n';
    return 0;
}
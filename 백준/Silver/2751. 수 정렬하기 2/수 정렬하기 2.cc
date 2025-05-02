#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000001];

int main(){
    int n;
    cin >> n;
    for(register int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for(register int i = 0; i < n; i++){
        cout << arr[i] << '\n';
    }
}
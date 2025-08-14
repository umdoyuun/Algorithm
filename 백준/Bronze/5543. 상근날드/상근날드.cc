#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int burgers[3], drinks[2], arr[6];
    for(int i = 0; i < 3; i++){
        cin >> burgers[i];
    }
    for(int i = 0; i < 2; i++){
        cin >> drinks[i];
        for(int j = 0; j < 3; j++){
            arr[i * 3 + j] = burgers[j] + drinks[i] - 50;
        }
    }
    sort(arr, arr + 6);
    cout << arr[0];
}
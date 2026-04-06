#include <iostream>
using namespace std;

int main(){
    int n, res = 0;
    char x;
    char arr[100001] = {0,};
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        cin >> x;
        if(x == arr[i]) res++;
    }
    cout << res << '\n';
}
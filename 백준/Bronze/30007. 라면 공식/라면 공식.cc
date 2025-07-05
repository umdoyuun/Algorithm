#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        int a,b,c;
        cin >> a >> b >> c;
        cout << a * (c - 1) + b << '\n';
    }
}
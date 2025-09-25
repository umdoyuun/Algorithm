#include <iostream>
using namespace std;

int main(){
    int n, a, b;
    cin >> n >> a >> b;
    if(a < b && a < n + a){
        cout << "Bus\n";
    }
    else if(a > b && b < n + a){
        cout << "Subway\n";
    }
    else cout << "Anything\n";
}
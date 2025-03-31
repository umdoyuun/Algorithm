#include <iostream>
using namespace std;

int main(){
    while(1){
        int x, y;
        cin >> x >> y;
        if(!x && !y) break;
        cout << x + y << '\n';
    }
}
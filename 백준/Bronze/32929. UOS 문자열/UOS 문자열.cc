#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    if((n - 1) % 3 == 0){
        cout << "U\n";
    }
    else if((n - 1) % 3 == 1){
        cout << "O\n";
    }
    else{
        cout << "S\n";
    }
}
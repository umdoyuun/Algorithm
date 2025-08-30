#include <iostream>
using namespace std;

int main(){
    string number;
    cin >> number;
    
    if (number.find("7") != string::npos) {
        if (stoi(number) % 7 == 0) {
            cout << 3 << endl;
        } else {
            cout << 2 << endl;
        }
    } else {
        if (stoi(number) % 7 == 0) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    
    return 0;
}
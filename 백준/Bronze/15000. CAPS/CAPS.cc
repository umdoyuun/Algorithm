#include <iostream>
using namespace std;

int main(){
    string str;
    cin >> str;
    for(char c : str){
        cout << char(c - 'a' + 'A');
    }
}
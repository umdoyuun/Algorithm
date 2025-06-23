#include <iostream>
using namespace std;

int main(){
    int T;
    string str;
    cin >> T;
    while(T--){
        cin >> str;
        for(auto c : str){
            if(c <= 'Z') cout << char(c - 'A' + 'a');
            else cout << c;
        }
        cout << '\n';
    }
}
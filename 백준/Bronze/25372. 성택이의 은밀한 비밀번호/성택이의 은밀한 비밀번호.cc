#include <iostream>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        string str;
        cin >> str;
        int s = str.size();
        if(s >= 6 && s <= 9){
            cout << "yes\n";
        }
        else{
            cout << "no\n";
        }
    }
}
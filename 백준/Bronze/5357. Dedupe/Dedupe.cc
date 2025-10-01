#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        for(int i = 0; i < str.size(); i++){
            if(i > 0 && str[i] == str[i - 1]) continue;
            cout << str[i];
        }
        cout << '\n';
    }
}
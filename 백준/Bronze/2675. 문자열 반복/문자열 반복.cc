#include <iostream>
using namespace std;

int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        string str;
        cin >> str;
        for(auto c : str){
            for(int i = 0; i < n; i++){
                cout << c;
            }
        }
        cout << '\n';
    }
}
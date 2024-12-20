#include <iostream>
using namespace std;

int main(){
    string str;
    int res = 1;
    cin >> str;
    int s = str.size();
    for(int i = 0; i < s / 2; i++){
        if(str[i] != str[s - 1 - i]){
            res = 0;
            break;
        }
    }
    cout << res;
    return 0;
}
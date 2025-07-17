#include <iostream>
using namespace std;

char tar[5] = {'a', 'i', 'u', 'e', 'o'};

int main(){
    int n, res = 0;
    string str;
    cin >> n >> str;
    for(char c : str){
        for(int i = 0; i < 5; i++){
            if(c == tar[i]){
                res++;
                break;
            }
        }
    }
    cout << res;
}
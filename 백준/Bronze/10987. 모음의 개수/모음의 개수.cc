#include<iostream>
using namespace std;

int res;
char tar[5] = {'a', 'e', 'i', 'o', 'u'};

int main(){
    string str;
    cin >> str;
    for(char c : str){
        for(char t : tar){
            if(t == c){
                res++;
                break;
            }
        }
    }
    cout << res;
}
#include<iostream>
using namespace std;

int main(){
    string str;
    cin >> str;
    for(char c : str){
        if(c <= 'Z'){
            cout << char(c + 'a' - 'A');
        }
        else{
            cout << char(c + 'A' - 'a');
        }
    }
}
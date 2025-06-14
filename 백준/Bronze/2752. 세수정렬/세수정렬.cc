#include <iostream>
#include <set>
using namespace std;

int main(){
    int x;
    set<int> s;
    for(int i = 0; i < 3; i++){
        cin >> x;
        s.insert(x);
    }
    for(auto it : s){
        cout << it <<' ';
    }
}
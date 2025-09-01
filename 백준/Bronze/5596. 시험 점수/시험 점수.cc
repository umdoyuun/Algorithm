#include <iostream>
using namespace std;

int main(){
    int total[2] = { 0, };
    for(int i = 0; i < 4; i++){
        int x;
        cin >> x;
        total[0] += x;
    }
    for(int i = 0; i < 4; i++){
        int x;
        cin >> x;
        total[1] += x;
    }
    cout << (total[0] > total[1] ? total[0] : total[1]);
}
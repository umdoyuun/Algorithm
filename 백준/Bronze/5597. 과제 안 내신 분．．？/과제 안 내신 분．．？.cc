#include <iostream>
using namespace std;

bool student[31];

int main(){
    for(int i = 0; i < 28; i++){
        int x;
        cin >> x;
        student[x] = true;
    }
    for(int i = 1; i <=30; i++){
        if(!student[i]) cout << i <<'\n';
    }
}
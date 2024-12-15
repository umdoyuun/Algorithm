#include <iostream>
using namespace std;

bool visit[42];
int res;

int main(){
    for(int i = 0; i < 10; i++){
        int x;
        cin >> x;
        x %= 42;
        if(visit[x]) continue;
        visit[x] = true;
        res++;
    }
    cout << res <<'\n';
    return 0;
}
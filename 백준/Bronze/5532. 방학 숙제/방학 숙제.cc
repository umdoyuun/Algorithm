#include <iostream>
using namespace std;

int main(){
    int l, a, b, c, d;
    cin >> l >> a >> b >> c >> d;
    int math = a / c;
    int kor = b / d;
    if(a % c) math++;
    if(b % d) kor++;
    cout << l - (math > kor ? math : kor) << '\n';
}
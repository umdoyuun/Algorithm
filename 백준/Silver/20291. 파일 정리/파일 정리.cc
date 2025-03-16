#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    string str;
    map<string, int> m;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> str;
        int j = str.find('.');
        str = str.substr(j + 1);
        m[str]++;
    }
    for(auto iter = m.begin(); iter != m.end(); iter++){
        cout << iter->first << ' ' << iter->second << '\n';
    }
    return 0;
}
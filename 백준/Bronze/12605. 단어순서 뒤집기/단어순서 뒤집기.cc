#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    stack<string> s;
    cin >> t;
    cin.ignore();
    
    for (int tc = 1; tc <= t; tc++) {
        string line;
        getline(cin, line);
        
        stringstream ss(line);
        string word;
        
        while (ss >> word) {
            s.push(word);
        }
        
        cout << "Case #" << tc << ": ";
        
        while (!s.empty()) {
            cout << s.top();
            s.pop();
            if (!s.empty()) cout << " ";
        }
        cout << '\n';
    }
    return 0;
}
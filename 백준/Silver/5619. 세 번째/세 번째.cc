#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<int> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    int x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    vector<int> res;
    for (int i = 0; i < 5 && i < n; i++) {
        for (int j = 0; j < 5 && j < n; j++) {
            if (i == j) continue;
            res.push_back(stoi(to_string(v[i]) + to_string(v[j])));
        }
    }
    sort(res.begin(), res.end());
    cout << res[2] << '\n';
    return 0;
}
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int cnt[26];
int idx[26][10001];
int s_res, l_res;

void init() {
    s_res = 10001, l_res = 0;
    memset(cnt, 0, sizeof(cnt));
    memset(idx, 0, sizeof(idx));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        init();
        string str;
        cin >> str;
        int k;
        cin >> k;
        for (int i = 0; i < str.size(); i++) {
            int c = str[i] - 'a';
            idx[c][cnt[c]] = i;
            cnt[c]++;
            if (cnt[c] >= k) {
                s_res = min(s_res, i - idx[c][cnt[c] - k] + 1);
                l_res = max(l_res, i - idx[c][cnt[c] - k] + 1);
            }
        }
        if (s_res == 10001) {
            cout << "-1\n";
        }
        else {
            cout << s_res << ' ' << l_res << '\n';
        }
    }
    return 0;
}

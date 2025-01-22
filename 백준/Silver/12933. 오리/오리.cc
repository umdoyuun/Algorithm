#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

string str;
int cnt[5], res;
map<char, int> m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	m['q'] = 0;
	m['u'] = 1;
	m['a'] = 2;
	m['c'] = 3;
	m['k'] = 4;
	cin >> str;
	for (char c : str) {
		int x = m[c];
        if(x == 0) cnt[x]++;
        else if(cnt[x - 1] > cnt[x]) cnt[x]++;
        else{
            res = -1;
            break;
        }
		if (x == 4) {
			for (int i = 0; i < 5; i++) {
				res = max(res, cnt[i]);
				cnt[i]--;
			}
		}
	}
	for (int i = 0; i < 5;i++) {
		if (cnt[i]) res = -1;
	}
	cout << res;
	return 0;
}
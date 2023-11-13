#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define max(a,b) a > b ? a : b

int n, m;
vector<string> v;
vector<string> r_v;
int result;

void init() {
	r_v.clear();
	v.clear();
	result = 0;
}

bool check(string str) {
	bool flag = true;
	for (int i = 0; i < str.size() / 2; i++) {
		if (str[i] != str[str.size() - 1 - i]) {
			flag = false;
			break;
		}
	}
	return flag;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		init();
		cin >> n >> m;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			string str;
			cin >> str;
			v.push_back(str);
			reverse(str.begin(), str.end());
			if (v[i] == str) cnt++;
			r_v.push_back(str);
		}
		//sort(v.begin(), v.end());
		//sort(r_v.begin(), r_v.end());
		//for (int i = 0; i < n; i++) {
			//if (v[i] == r_v[i])
				//result += m;
		//}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (v[i] == r_v[j]) {
					result += m;
					continue;
				}
			}
		}
		if (cnt > 1) {
			result -= cnt * m;
			result += m;
		}
		cout << '#' << tc << ' ' << result << '\n';
	}
	return 0;
}
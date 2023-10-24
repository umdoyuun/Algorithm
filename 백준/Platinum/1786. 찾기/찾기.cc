#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string str, pattern;
vector<int> pi;
vector<int> result;

void get_pi(string p) {
	int m = p.length(),j = 0;
	pi.resize(m, 0);
	for (int i = 1; i < m; i++) {
		while (j > 0 && p[i] != p[j])
			j = pi[j - 1];
		if (p[i] == p[j])
			pi[i] = ++j;
	}
}
void kmp(string s, string p) {
	int n = s.length();
	int m = p.length();
	int j = 0;
	for (int i = 0; i < n; i++) {
		while ((j > 0) && (s[i] != p[j])) {
			j = pi[j - 1];
		}
		if (s[i] == p[j]) {
			if (j == (m - 1)) {
				result.push_back(i - m + 1);
				j = pi[j];
			}
			else j++;
		}
	}
}
int main() {
	getline(cin, str);
	getline(cin, pattern);
	
	get_pi(pattern);
	kmp(str, pattern);
	int cnt = result.size();
	cout << cnt << '\n';
	for (int i = 0; i < cnt; i++) {
		cout << result[i] + 1 << ' ';
	}
	return 0;
}
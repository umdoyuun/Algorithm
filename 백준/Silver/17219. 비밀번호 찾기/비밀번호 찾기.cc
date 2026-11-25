#include <iostream>
#include <map>
using namespace std;

int n, m;
map<string, string> mapper;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	string str1, str2;
	for (int i = 0; i < n; i++) {
		cin >> str1 >> str2;
		mapper[str1] = str2;
	}
	for (int i = 0; i < m; i++) {
		cin >> str1;
		cout << mapper[str1] << '\n';
	}
	return 0;
}
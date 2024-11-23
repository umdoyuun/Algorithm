#include <iostream>
#include <map>
using namespace std;

int arr[1000001];
map<int, int> m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		m[arr[i]] = 0;
	}
	int cnt = 0;
	for (auto it = m.begin(); it != m.end(); it++) {
		it->second = cnt++;
	}
	for (int i = 0; i < n; i++) {
		cout << m[arr[i]] << ' ';
	}
	return 0;
}
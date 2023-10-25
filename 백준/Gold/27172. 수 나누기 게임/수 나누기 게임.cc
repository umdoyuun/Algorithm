#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int n;
bool check[1000001];
int result[1000001];
int max_num;

void func() {
	for (int i = 0; i < v.size(); i++) {
		for (int j = v[i] * 2; j <= 1000000; j += v[i]) {
			if (check[j]) {
				result[v[i]]++;
				result[j]--;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
		check[x] = true;
		//max_num = max(max_num, x);
	}
	func();
	for (int i = 0; i < v.size(); i++) {
		cout << result[v[i]] << ' ';
	}
	return 0;
}
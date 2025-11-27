#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> lis;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	lis.reserve(n);
	int size = 1;
	int x;
	cin >> x;
	lis.push_back(x);
	for (int i = 1; i < n; i++) {
		cin >> x;
		if (x > lis[size - 1]) {
			lis.push_back(x);
			size++;
		}
		else {
			int pos = lower_bound(lis.begin(), lis.end(), x) - lis.begin();
			lis[pos] = x;
		}
		
	}
	cout << size;
	return 0;
}
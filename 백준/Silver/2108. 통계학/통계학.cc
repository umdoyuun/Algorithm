#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int cnt[8001];
int total, n, mid, Max;
vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		total += x;
		cnt[x + 4000]++;
		Max = max(Max, cnt[x + 4000]);
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	double average = double(total) / double(n);
	average = round(average);
	if (average == -0)
		average = 0;
	mid = v[n / 2];
	int range = v[n - 1] - v[0];
	int max_cnt = 0;
	int result = 0;
	for (int i = 0; i < v.size(); i++) {
		int x = v[i];
		if (cnt[x + 4000] == Max) {
			if (result == x) continue;
			max_cnt++;
			result = x;
			if (max_cnt == 2) {
				break;
			}
		}
	}
	cout << average << '\n' << mid << '\n' << result << '\n' << range;
	return 0;
}
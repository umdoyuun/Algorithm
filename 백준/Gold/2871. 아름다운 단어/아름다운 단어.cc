#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n;
string str, sang = "", hee = "";
bool visit[100001];

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	cin >> str;
	for (int i = 0; i < n; i++) {
		pq.push({ str[i] - 'a', -i});
	}
	int idx = n - 1;
	while (!pq.empty() && idx >= 0) {
		while (visit[idx]) {
			idx--;
		}
		sang += str[idx];
		visit[idx] = true;
		idx--;
		while (!pq.empty() && visit[-pq.top().second]) {
			pq.pop();
		}
		if (pq.empty()) break;
		hee += 'a' + pq.top().first;
		visit[-pq.top().second] = true;
		pq.pop();
	}
	string result = "NE\n";
	if (hee < sang) result = "DA\n";
	cout << result << hee << '\n';
	return 0;
}
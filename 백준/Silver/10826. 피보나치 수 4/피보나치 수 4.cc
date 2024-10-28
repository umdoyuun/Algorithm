#include <iostream>
#include <string>
using namespace std;

int n;
bool visit[10005];
string dp[10005];

string sum(string a, string b) {
	if (a.size() < b.size()) {
		swap(a, b);
	}
	string ret = "";
	int x = 0;

	for (int i = 1; i <= a.size(); i++) {
		int idx1 = a.size() - i;
		int idx2 = b.size() - i;
		if (idx2 >= 0) {
			char tmp = a[idx1] + b[idx2] - '0' + x;
			x = 0;
			if (tmp > '9') {
				ret.insert(ret.begin(), (tmp - 10));
				x = 1;
			}
			else {
				ret.insert(ret.begin(), tmp);
			}
		}
		else {
			char tmp = a[idx1] + x;
			x = 0;
			if (tmp > '9') {
				ret.insert(ret.begin(), (tmp - 10));
				x = 1;
			}
			else {
				ret.insert(ret.begin(), tmp);
			}
		}
		
	}
	if (x) {
		ret.insert(ret.begin(), '1');
	}
	return ret;
}

string fibo(int x) {
	if (x == 0) {
		visit[x] = true;
		return "0";
	}
	if (x == 1) {
		visit[x] = true;
		return dp[x] = "1";
	}
	if (visit[x]){
		return dp[x];
	}
	visit[x] = true;
	return dp[x] = sum(fibo(x - 2), fibo(x - 1));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	cout << fibo(n);
	return 0;
}
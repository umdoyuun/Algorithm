#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
double result;
double arr[101][2];		//0 : x  1 : y
int par[101];
struct node {
	int a, b;
	double cost;
};

vector<node> v;

bool compare(node x, node y) {
	return x.cost < y.cost;
}

int getParent(int x) {
	if (x == par[x]) return x;
	else return par[x] = getParent(par[x]);
}

bool unionParent(int x, int y) {
	x = getParent(x);
	y = getParent(y);
	if (x == y) return false;
	par[x] = y;
	return true;
}

double Pow(double x) {
	return x * x;
}

void make_edge() {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			node X;
			X.a = i;
			X.b = j;
			X.cost = sqrt(Pow(arr[i][0] - arr[j][0]) + Pow(arr[i][1] - arr[j][1]));
			v.push_back(X);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		par[i] = i;
		cin >> arr[i][0] >> arr[i][1];
	}
	make_edge();
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++) {
		if (unionParent(v[i].a, v[i].b)) {
			result += v[i].cost;
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << result << '\n';

	return 0;
}
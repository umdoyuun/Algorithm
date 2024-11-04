#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int n, m;
int inDegree[1001];
string name_list[1001];
vector<int> child[1001];
vector<int> v[1001];
vector<int> a_list;
map<string, int> M;

void topology_sort() {
	priority_queue<int> pq;
	for (int i = 0; i < n; i++) {
		if (inDegree[i] == 0) {
			a_list.push_back(i);
			pq.push(i);
		}
	}
	while (!pq.empty()) {
		int x = pq.top();
		pq.pop();
		for (int i = 0; i < v[x].size(); i++) {
			inDegree[v[x][i]]--;
			if (inDegree[v[x][i]] == 0) {
				pq.push({ v[x][i] });
				child[x].push_back(v[x][i]);
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
		cin >> name_list[i];
	}
	sort(name_list, name_list + n);
	for (int i = 0; i < n; i++) {
		M[name_list[i]] = i;
	}
	cin >> m;

	for (int i = 0; i < m; i++) {
		string a, b;
		cin >> a >> b;
		inDegree[M[a]]++;
		v[M[b]].push_back(M[a]);
	}
	topology_sort();
	cout << a_list.size() << '\n';
	for (int i = 0; i < a_list.size(); i++) {
		cout << name_list[a_list[i]] << ' ';
	}
	cout << '\n';
	for (int i = 0; i < n; i++) {
		cout << name_list[i] << ' ';
		cout << child[i].size() << ' ';
		sort(child[i].begin(), child[i].end());
		for (int j = 0; j < child[i].size(); j++) {
			cout << name_list[child[i][j]] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
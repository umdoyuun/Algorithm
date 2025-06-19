#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int n, m, N, M, res;
string str[2001], pat[2001];
unsigned long long hash_map[2001][2001];
unsigned long long t_hash;

void findstr(){
	unsigned long long h = 0, p = 1;
	for (int i = 1; i < m; i++) p *= 7;
	for (int i = 0; i < N; i++) {
		h = 0;
		for (int j = 0; j < m; j++) {
			h = h * 7 + str[i][j];
		}
		for (int j = m; j <= M; j++) {
			hash_map[i][j - m] = h;
			h = 7 * (h - str[i][j - m] * p) + str[i][j];
		}
	}
	p = 1;
	for (int i = 1; i < n; i++) p *= 11;
	for (int i = 0; i <= M - m; i++) {
		h = 0;
		for (int j = 0; j < n; j++) {
			h = h * 11 + hash_map[j][i];
		}
		for (int j = n; j <= N; j++) {
			if (h == t_hash) res++;
			h = 11 * (h - hash_map[j - n][i] * p) + hash_map[j][i];
		}
	}
}

void find_t() {
	unsigned long long h = 0;
	for (int i = 0; i < n; i++) {
		h = 0;
		for (int j = 0; j < m; j++) {
			h = h * 7 + pat[i][j];
		}
		t_hash = t_hash * 11 + h;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> N >> M;
	for (int i = 0; i < n; i++) {
		cin >> pat[i];
	}
	for (int i = 0; i < N; i++) {
        cin >> str[i];
    }
    find_t();
	findstr();
	cout << res << '\n';
	return 0;
}
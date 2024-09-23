#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;


int p_cnt, cur;
map<string, int> mapper[100005];
set<string> album[100005];
string name[100005];
int par[100005];
int alb_cnt[100005];
int pic_cnt[100005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("sample_input.txt", "r", stdin);

	int n;
	cin >> n;
	name[0] = "album";
	for (register int i = 0; i < n; i++) {
		string cmd, str;
		cin >> cmd;
		if (cmd.compare("mkalb") == 0) {
			cin >> str;
			if (mapper[cur].count(str)) {
				cout << "duplicated album name\n";
			}
			else {
				mapper[cur][str] = ++p_cnt;
				par[p_cnt] = cur;
				name[p_cnt] = str;
				int idx = cur;
				while (idx != par[idx]) {
					alb_cnt[idx]++;
					idx = par[idx];
				}
				alb_cnt[idx]++;
			}
		}
			// RMALB
		else if (cmd.compare("rmalb") == 0) {
			cin >> str;
			if (mapper[cur].empty()) {
				cout << "0 0\n";
				continue;
			}
			if (str == "-1") {

				auto it = mapper[cur].begin();
				int idx = it->second;
				mapper[cur].erase(it);
				int alb_s = alb_cnt[idx] + 1;
				int pic_s = pic_cnt[idx];
				while (par[idx] != idx) {
					alb_cnt[idx] -= alb_s;
					pic_cnt[idx] -= pic_s;
					idx = par[idx];
				}
				alb_cnt[idx] -= alb_s;
				pic_cnt[idx] -= pic_s;
				cout << alb_s << ' ' <<  pic_s << '\n';
			}
			else if (str == "0") {
				mapper[cur].clear();
				int idx = cur;
				int alb_s = alb_cnt[cur];
				int pic_s = pic_cnt[cur] - album[cur].size();
				while (par[idx] != idx) {
					alb_cnt[idx] -= alb_s;
					pic_cnt[idx] -= pic_s;
					idx = par[idx];
				}
				alb_cnt[idx] -= alb_s;
				pic_cnt[idx] -= pic_s;
				cout << alb_s << ' ' << pic_s << '\n';
			}
			else if (str == "1") {
				auto it = mapper[cur].rbegin();
				int idx = it->second;
				mapper[cur].erase(it->first);
				int alb_s = alb_cnt[idx] + 1;
				int pic_s = pic_cnt[idx];
				while (par[idx] != idx) {
					alb_cnt[idx] -= alb_s;
					pic_cnt[idx] -= pic_s;
					idx = par[idx];
				}
				alb_cnt[idx] -= alb_s;
				pic_cnt[idx] -= pic_s;
				cout << alb_s << ' ' << pic_s << '\n';
			}
			else {
				auto it = mapper[cur].find(str);

				if (it != mapper[cur].end()) {
					int idx = it->second;
					int alb_s = alb_cnt[idx] + 1;
					int pic_s = pic_cnt[idx];
					mapper[cur].erase(it);
					while (par[idx] != idx) {
						alb_cnt[idx] -= alb_s;
						pic_cnt[idx] -= pic_s;
						idx = par[idx];
					}
					alb_cnt[idx] -= alb_s;
					pic_cnt[idx] -= pic_s;
					cout << alb_s << ' ' << pic_s << '\n';
				}
				else {
					cout << "0 0\n";
				}
			}
		}
		// Insert
		else if (cmd.compare("insert") == 0) {
			cin >> str;
			if (album[cur].count(str)) {
				cout << "duplicated photo name\n";
			}
			else {
				album[cur].insert(str);
				int idx = cur;
				while (idx != par[idx]) {
					pic_cnt[idx]++;
					idx = par[idx];
				}
				pic_cnt[idx]++;
			}
		}
		//delete
		else if (cmd.compare("delete") == 0) {
			cin >> str;
			if (album[cur].empty()) {
				cout << "0\n";
				continue;
			}
			if (str == "-1") {
				auto it = album[cur].begin();
				album[cur].erase(it);
				int idx = cur;
				while (idx != par[idx]) {
					pic_cnt[idx]--;
					idx = par[idx];
				}
				pic_cnt[idx]--;
				cout << "1\n";
			}
			else if (str == "0") {
				int s = album[cur].size();
				album[cur].clear();
				
				int idx = cur;
				while (idx != par[idx]) {
					pic_cnt[idx] -= s;
					idx = par[idx];
				}
				pic_cnt[idx] -= s;
				cout << s << '\n';
			}
			else if (str == "1") {
				auto it = album[cur].rbegin();
				album[cur].erase(*it);
				int idx = cur;
				while (idx != par[idx]) {
					pic_cnt[idx]--;
					idx = par[idx];
				}
				pic_cnt[idx]--;
				cout << "1\n";
			}
			else {
				auto it = album[cur].find(str);
				if (it != album[cur].end()) {
					album[cur].erase(it);
					int idx = cur;
					while (idx != par[idx]) {
						pic_cnt[idx]--;
						idx = par[idx];
					}
					pic_cnt[idx]--;
					cout << "1\n";
				}
				else {
					cout << "0\n";
				}
			}
		}
		else {
			cin >> str;
			if (str.compare("..") == 0) {
				cur = par[cur];
			}
			else if (str.compare("/") == 0) {
				cur = 0;
			}
			else {
				if (mapper[cur].count(str)) {
					cur = mapper[cur][str];
				}
			}
			cout << name[cur] << '\n';
		}
		//cout << "info : " <<  name[cur] << ' ' << alb_cnt[cur] << ' ' << pic_cnt[cur] << '\n';
		
	}
	return 0;
}
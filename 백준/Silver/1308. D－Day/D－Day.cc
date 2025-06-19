#include <iostream>
using namespace std;

int res, t_y, y, t_m, m, t_d, d;

int month_day[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int cnt_day(int year, int month, int day) {
	int cnt = 0;
	for (int i = 0; i < month - 1; i++) {
		cnt += month_day[i];
	}
	if (year % 4 == 0 && month > 2) {
		cnt++;
		if (year % 100 == 0) {
			cnt--;
		}
		if (year % 400 == 0) {
			cnt++;
		}
	}
	return cnt + day;
}

int sync_year(int year, int target_year) {
	int cnt = 0;
	for (int i = year; i < target_year; i++) {
		cnt += 365;
		if (i % 4 == 0) {
			cnt++;
		}
		if (i % 100 == 0) {
			cnt--;
		}
		if (i % 400 == 0) {
			cnt++;
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> y >> m >> d >> t_y >> t_m >> t_d;
	if(y + 1000 <= t_y){
		if (y + 1000 == t_y) {
			if (m < t_m ) {
				cout << "gg";
				return 0;
				
			}
			if (m == t_m && d <= t_d) {
				cout << "gg";
				return 0;
			}
		}
		else {
			cout << "gg";
			return 0;
		}
		
	}
	if (t_y == y) {
		res = cnt_day(t_y, t_m, t_d) - cnt_day(y, m, d);
	}
	else {
		res = cnt_day(y, 12, 31) - cnt_day(y, m, d);
		res += sync_year(y + 1, t_y) + cnt_day(t_y, t_m, t_d);
	}
	cout << "D-" << res << '\n';
	return 0;
}
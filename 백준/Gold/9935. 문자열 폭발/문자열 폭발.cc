#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string str, pattern, tmp = "";
	int s_size, p_size, tmp_size = 0;
	cin >> str >> pattern;
	s_size = str.size();
	p_size = pattern.size();
	for (int i = 0; i < s_size; i++) {
		tmp += str[i];
		tmp_size++;
		if (tmp_size >= p_size) {
			int flag = 1;
			for (int j = 0; j < p_size; j++) {
				if (tmp[tmp_size - p_size + j] != pattern[j]) {
					flag = 0;
					break;
				}
			}
			if (flag) {
				tmp.erase(tmp.end() - p_size, tmp.end());
				tmp_size -= p_size;
			}
		}
	}
	if (tmp_size) {
		cout << tmp << '\n';
	}
	else {
		cout << "FRULA\n";
	}
	return 0;
}
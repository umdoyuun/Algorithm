#include <iostream>
#include <string>
using namespace std;

char s[100001];
int s_idx;
bool flag;

void print_s() {
	while (s_idx) {
		cout << s[--s_idx];
	}
}

int main() {
	string str;
	getline(cin, str);
	for (char c : str) {
		if (c == '<') {
			print_s();
			flag = true;
		}
		if (flag) {
			cout << c;
		}
		else {
			if (c == ' ') {
				print_s();
				cout << c;
			}
			else {
				s[s_idx++] = c;
			}			
		}
		if (c == '>') {
			flag = false;
		}
	}
	print_s();
	return 0;
}
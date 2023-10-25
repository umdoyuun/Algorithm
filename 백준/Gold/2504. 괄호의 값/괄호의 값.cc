#include <iostream>
#include <stack>
#include <string>
using namespace std;

int result;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string str;
	stack<char> s;
	cin >> str;
	int tmp = 1;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			s.push(str[i]);
			tmp *= 2;
		}
		else if (str[i] == '[') {
			s.push(str[i]);
			tmp *= 3;
		}
		else {
			if (s.empty()) {
				result = 0;
				break;
			}
			if ((s.top() == '(' && str[i] == ']') || (s.top() == '[' && str[i] == ')')) {
				result = 0;
				break;
			}
			if (i > 0) {
				if (str[i - 1] == ')' || str[i - 1] == ']') {
					if (str[i] == ')') {
						tmp /= 2;
					}
					else if (str[i] == ']') {
						tmp /= 3;
					}
					s.pop();
					continue;
				}
			}
			if (str[i] == ')') {
				result += tmp;
				tmp /= 2;
			}
			else if (str[i] == ']') {
				result += tmp;
				tmp /= 3;
			}
			s.pop();
		}
	}
	if (!s.empty()) result = 0;
	cout << result;
	return 0;
}
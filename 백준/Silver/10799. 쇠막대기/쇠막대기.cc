#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string str;
	int result = 0;
	stack<char> s;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (i < str.size() - 1) {
			if (str[i] == '(' && str[i + 1] == ')') {
				//레이저
				result += s.size();
				i++;
				continue;
			}
		}
		if (str[i] == '(') {
			s.push('(');
		}
		else {
			result++;
			s.pop();
		}
	}
	cout << result;
	return 0;
}
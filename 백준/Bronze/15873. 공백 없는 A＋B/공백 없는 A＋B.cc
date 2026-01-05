#include <iostream>
using namespace std;

int main() {
	string str;
	cin >> str;
	int sum = 0;
	if (str.size() == 4) {
		sum = 20;
	}
	else if (str[1] == '0') {
		sum = 10 + str[2] - '0';
	}
	else if (str[2] == '0') {
		sum = 10 + str[0] - '0';
	}
	else {
		sum = str[0] - '0' + str[1] - '0';
	}
	cout << sum;
}
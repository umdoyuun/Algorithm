#include <iostream>
#include <string>
using namespace std;

string str[5];

int main() {
	int Max = 0;
	for (int i = 0; i < 5; i++) {
		cin >> str[i];
		if (str[i].size() > Max) {
			Max = str[i].size();
		}
	}
	for (int i = 0; i < Max; i++) {
		for (int j = 0; j < 5; j++) {
			if (str[j].size() <= i) continue;
			cout << str[j][i];
		}
	}
	return 0;
}
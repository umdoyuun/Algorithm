#include <iostream>
using namespace std;

string strs[3] = { "Panthera tigris\n", "Forsythia koreana\n", "Pinus densiflora\n" };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string str;
	while (1) {
		cin >> str;
		if (str[0] == 'e') {
			break;
		}
		else if (str[0] == 'a') {
			cout << strs[0];
		}
		else if (str[0] == 'f') {
			cout << strs[1];
		}
		else {
			cout << strs[2];
		}
	}
	return 0;
}
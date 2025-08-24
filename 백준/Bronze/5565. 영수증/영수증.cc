#include <iostream>
using namespace std;

int main(){
	int totalPrice;
	int sum = 0;
	int num;

	cin >> totalPrice;

	for (int i = 0; i < 9; ++i) {
		cin >> num;
		sum += num;
	}

	cout << totalPrice - sum << endl;

	return 0;
}
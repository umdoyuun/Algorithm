#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int arr[4];
	int up = 0;
	int down = 0;
	int same = 0;

	for (int i = 0; i < 4; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i < 4; i++) {
		if (arr[i] > arr[i - 1])
			up++;
		else if (arr[i] < arr[i - 1])
			down++;
		else
			same++;
	}
	if (up == 3)
		cout << "Fish Rising";
	else if (down == 3)
		cout << "Fish Diving";
	else if (same == 3)
		cout << "Fish At Constant Depth";
	else
		cout << "No Fish";

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int arr[1000001], buffer[1000001];
long long result = 0;

void merge(int begin, int mid, int end) {
	int idx = 0;
	int begin1 = begin;
	int begin2 = mid;
	while (begin1 < mid && begin2 < end) {
		if (arr[begin1] < arr[begin2])
			buffer[idx++] = arr[begin1++];
		else if (arr[begin1] > arr[begin2]) {
			result += mid - begin1;
			buffer[idx++] = arr[begin2++];
		}
	}
	while (begin1 < mid) {
		buffer[idx++] = arr[begin1++];
	}
	while (begin2 < end) {
		buffer[idx++] = arr[begin2++];
	}
	for (int i = 0; i < end - begin; i++)
		arr[begin + i] = buffer[i];
}

void merge_sort(int begin, int end) {
	if (end - begin <= 1) return;
	int mid = begin + (end - begin) / 2;
	merge_sort(begin, mid);
	merge_sort(mid, end);
	merge(begin, mid, end);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	merge_sort(0, n);
	cout << result << '\n';
	return 0;
}
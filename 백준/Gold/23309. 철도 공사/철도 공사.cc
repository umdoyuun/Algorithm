#include <iostream>
#include <string>
using namespace std;

int n, m;

struct node {
	int next, prev;
};

node pool[1000001];

int head = -1, tail = -1;

void insert_back(int data) {
	if (head == -1) {
		head = data;
		tail = head;
	}
	else {
		pool[tail].next = data;
		pool[data].prev = tail;
		tail = data;
	}
	return;
}

void insert(int s, int type, int data) {
	//type 0: 뒤로, type 1: 앞으로
	switch (type) {
	case 0:
		if (s == head) {
			pool[data].next = head;
			pool[head].prev = data;
			head = data;
			cout << tail << '\n';
		}
		else {
			cout << pool[s].prev << '\n';
			pool[data].next = s;
			pool[data].prev = pool[s].prev;
			pool[pool[s].prev].next = data;
			pool[s].prev = data;
		}
		break;
	case 1:
		if (s == tail) {
			cout << head << '\n';
			pool[data].prev = tail;
			pool[tail].next = data;
			tail = data;
		}
		else {
			cout << pool[s].next << '\n';
			pool[data].next = pool[s].next;
			pool[data].prev = s;
			pool[pool[s].next].prev = data;
			pool[s].next = data;
		}
	}
	return;
}

void Delete(int s, int type) {
	//type 0 : 뒤로 1: 앞으로
	switch (type) {
	case 0:
		if (head == s) {
			cout << tail << '\n';
			tail = pool[tail].prev;
			pool[tail].next = -1;
		}
		else {
			cout << pool[s].prev << '\n';
			if (pool[s].prev == head) {
				head = pool[head].next;
				pool[head].prev = -1;
			}
			else {
				pool[s].prev = pool[pool[s].prev].prev;
				pool[pool[s].prev].next = s;
			}
		}
		break;
	case 1:
		if (tail == s) {
			cout << head << '\n';
			head = pool[head].next;
			pool[head].prev = -1;
		}
		else {
			cout << pool[s].next << '\n';
			if (pool[s].next == tail) {
				tail = pool[tail].prev;
				pool[tail].next = -1;
			}
			else {
				pool[s].next = pool[pool[s].next].next;
				pool[pool[s].next].prev = s;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		insert_back(x);
	}
	for (int i = 0; i < m; i++) {
		string cmd;
		cin >> cmd;
		if (cmd == "BN") {
			int x, y;
			cin >> x >> y;
			insert(x, 1, y);
		}
		else if (cmd == "BP") {
			int x, y;
			cin >> x >> y;
			insert(x, 0, y);
		}
		else if (cmd == "CN") {
			int x;
			cin >> x;
			Delete(x, 1);
		}
		else {
			int x;
			cin >> x;
			Delete(x, 0);

		}
	}
	return 0;
}
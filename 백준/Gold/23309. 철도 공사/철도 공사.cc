#include <iostream>
#include <string>
using namespace std;

int n, m;

struct node {
	int x;
	node* next;
	node* prev;
};

node pool[1000001];

node* head, * tail;

node* get_node(int data) {
	pool[data].x = data;
	pool[data].next = nullptr;
	pool[data].prev = nullptr;
	return &pool[data];
}


void insert_back(int data) {
	node* n_node = get_node(data);
	if (head == nullptr) {
		head = n_node;
		tail = head;
	}
	else {
		tail->next = n_node;
		n_node->prev = tail;
		tail = n_node;
	}
	return;
}

void insert(int s, int type, int data) {
	node* n_node = get_node(data);
	//type 0: 뒤로, type 1: 앞으로
	node* list = &pool[s];
	switch (type) {
	case 0:
		if (list == head) {
			n_node->next = head;
			head->prev = n_node;
			head = n_node;
			cout << tail->x << '\n';
		}
		else {
			cout << list->prev->x << '\n';
			n_node->next = list;
			n_node->prev = list->prev;
			list->prev->next = n_node;
			list->prev = n_node;
		}
		break;
	case 1:
		if (list == tail) {
			cout << head->x << '\n';
			n_node->prev = tail;
			tail->next = n_node;
			tail = n_node;
		}
		else {
			cout << list->next->x << '\n';
			n_node->next = list->next;
			n_node->prev = list;
			list->next->prev = n_node;
			list->next = n_node;
		}
	}
	return;
}

void Delete(int s, int type) {
	node* list = &pool[s];
	//type 0 : 뒤로 1: 앞으로
	switch (type) {
	case 0:
		if (head == list) {
			cout << tail->x << '\n';
			tail = tail->prev;
			tail->next = nullptr;
		}
		else {
			cout << list->prev->x << '\n';
			if (list->prev == head) {
				head = head->next;
				head->prev = nullptr;
			}
			else {
				list->prev = list->prev->prev;
				list->prev->next = list;
			}
		}
		break;
	case 1:
		if (tail == list) {
			cout << head->x << '\n';
			head = head->next;
			head->prev = nullptr;
		}
		else {
			cout << list->next->x << '\n';
			if (list->next == tail) {
				tail = tail->prev;
				tail->next = nullptr;
			}
			else {
				list->next = list->next->next;
				list->next->prev = list;
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
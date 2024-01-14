#include <iostream>
#include <list>
using namespace std;

int n, m;
list<int> pw;

void insert() {
	int start, r;
	cin >> start >> r;
	list<int>::iterator iter = pw.begin();
	for (int i = 0; i < start && iter != pw.end(); i++) iter++;
	for(int i = 0; i < r; i++){
		int s;
		cin >> s;
		pw.insert(iter, s);
	}
}

void Delete() {
	int start, r;
	cin >> start >> r;
	list<int>::iterator iter = pw.begin();
	for (int i = 0; i < start && iter != pw.end(); i++) iter++;
	for (int i = 0; i < r; i++) {
		iter = pw.erase(iter);
	}
}

void print() {
	list<int>::iterator iter = pw.begin();
	for (int i = 0; i < 10 && iter != pw.end(); i++) {
		cout << *iter << ' ';
		iter++;
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for (int tc = 1; tc <= 10; tc++) {
		cin >> n;
		pw.clear();
		for (int i = 0; i < n; i++) {
			int password;
			cin >> password;
			pw.push_back(password);
		}
		cin >> m;
		for (int i = 0; i < m; i++) {
			char cmd;
			cin >> cmd;
			switch (cmd) {
			case 'I':
				insert();
				break;
			case 'D':
				Delete();
				break;
			case 'A':
				int r;
				cin >> r;
				for (int i = 0; i < r; i++) {
					int s;
					cin >> s;
					pw.push_back(s);
				}
				break;
			}
		}
		cout << '#' << tc << ' ';
		print();
	}
	return 0;
}
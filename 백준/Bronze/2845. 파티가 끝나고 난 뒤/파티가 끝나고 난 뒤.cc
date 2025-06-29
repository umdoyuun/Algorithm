#include <iostream>
using namespace std;
int main() {
    int n, x, news;
    cin >> n >> x;
    for (int i = 0; i < 5; i++)
    {
        cin >> news;
        cout << news - n * x << ' ';
    }
}
#include <iostream>
using namespace std;

int main() {
  int x, y;
  cin >> x >> y;

  if (x >= 3 && y <= 4) {
    cout << "TroyMartian\n";
  }
  if (x <= 6 && y >= 2) {
    cout << "VladSaturnian\n";
  }
  if (x <= 2 && y <= 3) {
    cout << "GraemeMercurian\n";
  }

}
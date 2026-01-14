#include <iostream>
#include <algorithm>
using namespace std;

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   int arr[9], sum = 0;
   for (int i = 0; i < 9; i++) {
      cin >> arr[i];
      sum += arr[i];
   }
   int tar = sum - 100;
   bool flag = false;
   for (int i = 0; i < 8; i++) {
      for (int j = i + 1; j < 9; j++) {
         if (arr[i] + arr[j] == tar) {
            arr[i] = 0;
            arr[j] = 0;
            flag = true;
            break;
         }
      }
      if(flag) break;
   }
   sort(arr, arr + 9);
   for (int i = 2; i < 9; i++) {
      cout << arr[i] << '\n';
   }
   return 0;
}
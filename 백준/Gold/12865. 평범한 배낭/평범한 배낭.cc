#include <iostream>
using namespace std;
#define max(a,b) a>b ? a:b

int n, k, w[101], v[101];
int dp[101][100001];

void knapsack() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j - w[i] >= 0) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
}
int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    knapsack();
    cout << dp[n][k];
    return 0;
}
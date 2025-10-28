#include <iostream>
#include <algorithm>
using namespace std;

const long long mx = 1e9 + 7;

int n;
struct node {
    int n;
    int cnt[27];
    node* child[27];
};

node* root;
node pool[1000000];
int p_cnt;
long long dp[3001];
long long res;

node* new_node() {
    for (int i = 0; i < 27; i++) {
        pool[p_cnt].child[i] = nullptr;
    }
    return &pool[p_cnt++];
}

void insert(string str, string cmp) {
    node* cur = root;
    bool flag = true;
    for (int i = 0; i < str.size(); i++) {
        int x = str[i] - 'A';
        if (!cur->cnt[x]) {
           
            cur->n++;
        }
        cur->cnt[x]++;
        if (!cur->child[x]) {
            cur->child[x] = new_node();
        }
        if (cur->cnt[x] == 1 && str[i] != cmp[i]) {
            flag = false;
            break;
        }
        cur = cur->child[x];

    }
    if (flag) {
        if (!cur->cnt[26]) {
            cur->n++;
        }
        cur->cnt[26]++;
    }
}

long long calc(int k) {
    if (dp[k]) return dp[k];
    if (k <= 1) return 1;
    return dp[k] = (k * calc(k - 1)) % mx;
}

void search(node x) {
    res = (res * calc(x.n)) % mx;
    for (int i = 0; i < 26; i++) {
        if (x.cnt[i] > 1) {

            search(*x.child[i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    root = new_node();
    string str_arr[3001];
    for (int i = 0; i < n; i++) {
        cin >> str_arr[i];
    }
    sort(str_arr, str_arr + n);
    for (int i = 0; i < n - 1; i++) {
        insert(str_arr[i], str_arr[i + 1]);
    }
    insert(str_arr[n - 1], str_arr[n - 1]);
    res = 1;
    search(*root);
    cout << res << '\n';
    return 0;
}
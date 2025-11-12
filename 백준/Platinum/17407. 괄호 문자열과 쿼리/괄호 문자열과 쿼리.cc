#include <iostream>
using namespace std;

class node {
public:
    int sum;
    int min_prefix;
};

node seg[100000 * 4];
int arr[100001];

node init(int x, int s, int e) {
    if (s == e) {
        return seg[x] = { arr[s], arr[s] };
    }
    int mid = s + (e - s) / 2;
    node left = init(x * 2, s, mid);
    node right = init(x * 2 + 1, mid + 1, e);

    seg[x].sum = left.sum + right.sum;
    seg[x].min_prefix = min(left.min_prefix, left.sum + right.min_prefix);
    return seg[x];
}

node update(int x, int s, int e, int idx) {
    if (idx < s || idx > e) return seg[x];
    if (s == e) {
        seg[x].sum *= -1;
        seg[x].min_prefix = seg[x].sum;
        return seg[x];
    }
    int mid = s + (e - s) / 2;
    node left = update(x * 2, s, mid, idx);
    node right = update(x * 2 + 1, mid + 1, e, idx);

    seg[x].sum = left.sum + right.sum;
    seg[x].min_prefix = min(left.min_prefix, left.sum + right.min_prefix);
    return seg[x];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str;
    cin >> str;
    int n = str.size(), m, res = 0;

    for (int i = 0; i < n; i++) {
        arr[i] = (str[i] == '(') ? 1 : -1;
    }

    init(1, 0, n - 1);
    cin >> m;

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        update(1, 0, n - 1, x - 1);

        if (seg[1].sum == 0 && seg[1].min_prefix >= 0) {
            res++;
        }
    }

    cout << res;
    return 0;
}
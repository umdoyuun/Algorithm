#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define INF 0x7fffffff


struct node {
    long long sum, max, min;
};

struct Lazy {
    long long sum, div;
};
long long arr[100001];
node seg[100001 * 4];
Lazy lazy[100001 * 4];

void init(int x, int s, int e) {
    lazy[x].div = INF;
    if (s == e) {
        seg[x] = { arr[s], arr[s], arr[s] };
        return;
    }
    int mid = s + (e - s) / 2;
    init(x * 2, s, mid);
    init(x * 2 + 1, mid + 1, e);
    seg[x] = { seg[x * 2].sum + seg[x * 2 + 1].sum , max(seg[x * 2].max, seg[x * 2 + 1].max), min(seg[x * 2].min, seg[x * 2 + 1].min) };
}

void lazy_update(int x, int s, int e) {
    if (!lazy[x].sum && lazy[x].div == INF) return;
    if (lazy[x].div == INF) {
        seg[x].sum += (e - s + 1) * lazy[x].sum;
        seg[x].max += lazy[x].sum;
        seg[x].min += lazy[x].sum;
        if (s != e) {
            for (int i = x * 2; i <= x * 2 + 1; i++) {
                lazy[i].sum += lazy[x].sum;
            }
        }
        lazy[x].sum = 0;
    }
    else {
        seg[x].sum = (e - s + 1) * (lazy[x].sum + lazy[x].div);
        seg[x].max = lazy[x].sum + lazy[x].div;
        seg[x].min = lazy[x].sum + lazy[x].div;
        if (s != e) {
            for (int i = x * 2; i <= x * 2 + 1; i++) {
                lazy[i].sum = lazy[x].sum;
                lazy[i].div = lazy[x].div;
            }
        }
        lazy[x] = { 0, INF };
    }
}

void update_div(int x, int s, int e, int l, int r, long long v) {
    lazy_update(x, s, e);
    if (r < s || e < l) return;
    if (l <= s && e <= r) {
        if (floor((double)seg[x].max / (double)v) == floor((double)seg[x].min / (double)v)) {
            lazy[x].div = floor((double)seg[x].max / (double)v);
            //if (lazy[x].div == 0) {
            //    cout << s << ' ' << e << '\n';
            //}
            lazy_update(x, s, e);
            return;
        }
        if (seg[x].max == seg[x].min + 1) {
            lazy[x].sum = floor((double)seg[x].min / (double)v) - seg[x].min;
            lazy_update(x, s, e);
            return;
        }
    }
    int mid = s + (e - s) / 2;
    update_div(x * 2, s, mid, l, r, v);
    update_div(x * 2 + 1, mid + 1, e, l, r, v);
    seg[x] = { seg[x * 2].sum + seg[x * 2 + 1].sum , max(seg[x * 2].max, seg[x * 2 + 1].max), min(seg[x * 2].min, seg[x * 2 + 1].min) };
}

void update_sum(int x, int s, int e, int l, int r, long long v) {
    lazy_update(x, s, e);
    if (r < s || e < l) return;
    if (l <= s && e <= r) {
        lazy[x].sum = v;
        lazy_update(x, s, e);
        return;
    }
    int mid = s + (e - s) / 2;
    update_sum(x * 2, s, mid, l, r, v);
    update_sum(x * 2 + 1, mid + 1, e, l, r, v);
    seg[x] = { seg[x * 2].sum + seg[x * 2 + 1].sum , max(seg[x * 2].max, seg[x * 2 + 1].max), min(seg[x * 2].min, seg[x * 2 + 1].min) };
}

long long query_sum(int x, int s, int e, int l, int r) {
    lazy_update(x, s, e);
    if (r < s || e < l) return 0;
    if (l <= s && e <= r) {
        return seg[x].sum;
    }
    int mid = s + (e - s) / 2;
    return query_sum(x * 2, s, mid, l, r) + query_sum(x * 2 + 1, mid + 1, e, l, r);
}

long long query_min(int x, int s, int e, int l, int r) {
    lazy_update(x, s, e);
    if (r < s || e < l) return INF;
    if (l <= s && e <= r) {
        return seg[x].min;
    }
    int mid = s + (e - s) / 2;
    return min(query_min(x * 2, s, mid, l, r), query_min(x * 2 + 1, mid + 1, e, l, r));
}

void print(int x, int s, int e, int t) {
    lazy_update(x, s, e);
    if (s == e) {
        if(t == 0)
        cout << seg[x].sum << ' ';
        else
            cout << seg[x].min << ' ';
        return;
    }
    int mid = s + (e - s) / 2;
    print(x * 2, s, mid, t);
    print(x * 2 + 1, mid + 1, e, t);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    init(1, 0, n - 1);
    for (int i = 0; i < m; i++) {
        int cmd, l, r;
        long long v;
        cin >> cmd >> l >> r;
        if (cmd == 1) {
            cin >> v;
            update_sum(1, 0, n - 1, l, r, v);
            /*print(1, 0, n - 1, 0);
            cout << '\n';*/
        }
        else if (cmd == 2) {
            cin >> v;
            update_div(1, 0, n - 1, l, r, v);
            /*print(1, 0, n - 1, 1);
            cout << '\n';*/
        }
        else if (cmd == 3) {
            /*print(1, 0, n - 1, 1);
            cout << '\n';*/
            cout << query_min(1, 0, n - 1, l, r) << '\n';
        }
        else {
            /*print(1, 0, n - 1, 0);
            cout << '\n';*/
            cout << query_sum(1, 0, n - 1, l, r) << '\n';

        }
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Query {
    int idx, l, r;
};

int n, m, sqrtn;
int cnt[1000001];
int s_cnt = 0;
vector<Query> queries;
vector<int> res;

bool compare(const Query& a, const Query& b) {
    if (a.l / sqrtn != b.l / sqrtn) {
        return a.l / sqrtn < b.l / sqrtn;
    }
    return a.r < b.r;
}

void add(int x) {
    if (cnt[x] == 0) s_cnt++;
    cnt[x]++;
}

void sub(int x) {
    cnt[x]--;
    if (cnt[x] == 0) s_cnt--;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    sqrtn = sqrt(n);
    
    vector<int> arr(n);
    vector<int> v(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        v[i] = arr[i];
    }
    
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    
    for (int i = 0; i < n; i++) {
        arr[i] = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
    }
    
    cin >> m;
    
    queries.resize(m);
    res.resize(m);
    
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        queries[i] = {i, l - 1, r - 1};
    }
    
    sort(queries.begin(), queries.end(), compare);
    
    int s = queries[0].l, e = queries[0].r;
    for (int i = s; i <= e; i++) {
        add(arr[i]);
    }
    res[queries[0].idx] = s_cnt;

    for (int i = 1; i < m; i++) {
        while (queries[i].l < s) {
            add(arr[--s]);
        }
        while (queries[i].r > e) {
            add(arr[++e]);
        }
        while (queries[i].l > s) {
            sub(arr[s++]);
        }
        while (queries[i].r < e) {
            sub(arr[e--]);
        }
        
        res[queries[i].idx] = s_cnt;
    }
    
    for (int i = 0; i < m; i++) {
        cout << res[i] << '\n';
    }
    
    return 0;
}
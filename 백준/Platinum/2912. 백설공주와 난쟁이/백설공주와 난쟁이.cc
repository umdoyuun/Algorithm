#include <iostream>
#include <algorithm>
#include <cmath>
#include <random>
#include <ctime>
using namespace std;

int n, c, m;
int arr[300001];
int cnt[10001];
struct Query {
    int idx, s, e;
};
Query query[10001];
string res[10001];
int sqn, s, e;

bool cmp(Query a, Query b) {
    if (a.s / sqn != b.s / sqn) return a.s < b.s;
    return a.e < b.e;
}

void add(int pos) {
    cnt[arr[pos]]++;
}

void remove(int pos) {
    cnt[arr[pos]]--;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    srand(time(NULL));
    
    cin >> n >> c;
    sqn = sqrt(n);
    
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        query[i] = {i, a, b};
    }
    
    sort(query + 1, query + 1 + m, cmp);
    
    s = query[1].s;
    e = query[1].e;
    for (int i = s; i <= e; i++) {
        add(i);
    }
    
    int len = e - s + 1;
    int majority = -1;
    
    for (int trial = 0; trial < 50; trial++) {
        int pos = s + rand() % len;
        int color = arr[pos];
        if (cnt[color] * 2 > len) {
            majority = color;
            break;
        }
    }
    
    if (majority != -1) {
        res[query[1].idx] = "yes " + to_string(majority);
    } else {
        res[query[1].idx] = "no";
    }
    
    for (int i = 2; i <= m; i++) {
        while (s > query[i].s) {
            s--;
            add(s);
        }
        while (e < query[i].e) {
            e++;
            add(e);
        }
        while (s < query[i].s) {
            remove(s);
            s++;
        }
        while (e > query[i].e) {
            remove(e);
            e--;
        }
        
        len = query[i].e - query[i].s + 1;
        majority = -1;
        
        for (int trial = 0; trial < 50; trial++) {
            int pos = query[i].s + rand() % len;
            int color = arr[pos];
            if (cnt[color] * 2 > len) {
                majority = color;
                break;
            }
        }
        
        if (majority != -1) {
            res[query[i].idx] = "yes " + to_string(majority);
        } else {
            res[query[i].idx] = "no";
        }
    }
    
    for (int i = 1; i <= m; i++) {
        cout << res[i] << '\n';
    }
    
    return 0;
}
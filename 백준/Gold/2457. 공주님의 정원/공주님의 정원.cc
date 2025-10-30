#include <iostream>
#include <algorithm>
using namespace std;

struct flower {
    int start, end;
};
flower f[100001];

bool cmp(const flower& a, const flower& b) {
    if (a.start == b.start) return a.end > b.end;
    return a.start < b.start;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int cur = 301, n, res = 0, maxEnd = 0;
    cin >> n;
    
    int sz = 0;
    for (int i = 0; i < n; i++) {
        int sm, sd, em, ed;
        cin >> sm >> sd >> em >> ed;
        int s = sm*100 + sd, e = em*100 + ed;
        if (e < 301 || s > 1130) continue;
        f[sz++] = { s, e };
    }
    
    sort(f, f + sz, cmp);
    
    int i = 0;
    while (cur < 1201) {
        maxEnd = 0;
        
        while (i < sz && f[i].start <= cur) {
            maxEnd = max(maxEnd, f[i].end);
            i++;
        }
        
        if (maxEnd == 0) {
            res = 0;
            break;
        }
        
        res++;
        cur = maxEnd;
    }
    
    cout << res << '\n';
    return 0;
}
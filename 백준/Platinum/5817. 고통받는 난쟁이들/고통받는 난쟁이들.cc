#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[200001];
int p[200001];

struct NodeV {
    int mx, mn;
} segPos[200001 * 4];

struct NodeP {
    int mnPos, mxPos;
} segValMin[200001 * 4];

NodeV initPos(int x, int s, int e) {
    if (s == e) return segPos[x] = { arr[s], arr[s] };
    int mid = (s + e) >> 1;
    NodeV L = initPos(x << 1, s, mid);
    NodeV R = initPos(x << 1 | 1, mid + 1, e);
    return segPos[x] = { max(L.mx, R.mx), min(L.mn, R.mn) };
}

NodeV updatePos(int x, int s, int e, int idx, int v) {
    if (idx < s || e < idx) return segPos[x];
    if (s == e) return segPos[x] = { v, v };
    int mid = (s + e) >> 1;
    NodeV L = updatePos(x << 1, s, mid, idx, v);
    NodeV R = updatePos(x << 1 | 1, mid + 1, e, idx, v);
    return segPos[x] = { max(L.mx, R.mx), min(L.mn, R.mn) };
}

NodeV queryPos(int x, int s, int e, int l, int r) {
    if (r < s || e < l) return { 0, 2000001 };
    if (l <= s && e <= r) return segPos[x];
    int mid = (s + e) >> 1;
    NodeV L = queryPos(x << 1, s, mid, l, r);
    NodeV R = queryPos(x << 1 | 1, mid + 1, e, l, r);
    return { max(L.mx, R.mx), min(L.mn, R.mn) };
}

NodeP initVal(int x, int s, int e) {
    if (s == e) {
        return segValMin[x] = { p[s], p[s] };
    }
    int mid = (s + e) >> 1;
    NodeP L = initVal(x << 1, s, mid);
    NodeP R = initVal(x << 1 | 1, mid + 1, e);
    segValMin[x].mnPos = min(L.mnPos, R.mnPos);
    segValMin[x].mxPos = max(L.mxPos, R.mxPos);
    return segValMin[x];
}

NodeP updateVal(int x, int s, int e, int idx, int pos) {
    if (idx < s || e < idx) return segValMin[x];
    if (s == e) return segValMin[x] = { pos, pos };
    int mid = (s + e) >> 1;
    NodeP L = updateVal(x << 1, s, mid, idx, pos);
    NodeP R = updateVal(x << 1 | 1, mid + 1, e, idx, pos);
    segValMin[x].mnPos = min(L.mnPos, R.mnPos);
    segValMin[x].mxPos = max(L.mxPos, R.mxPos);
    return segValMin[x];
}

NodeP queryVal(int x, int s, int e, int l, int r) {
    if (r < s || e < l) return { 2000001, 0 };
    if (l <= s && e <= r) return segValMin[x];
    int mid = (s + e) >> 1;
    NodeP L = queryVal(x << 1, s, mid, l, r);
    NodeP R = queryVal(x << 1 | 1, mid + 1, e, l, r);
    return { min(L.mnPos, R.mnPos), max(L.mxPos, R.mxPos) };
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        p[arr[i]] = i; 
    }

    initPos(1, 1, n);
    initVal(1, 1, n);

    for (int i = 0; i < m; ++i) {
        int cmd, x, y;
        cin >> cmd >> x >> y;
        if (cmd == 1) {
            int vx = arr[x];
            int vy = arr[y];

            swap(arr[x], arr[y]);

            p[vx] = y;
            p[vy] = x;

            updatePos(1, 1, n, x, arr[x]);
            updatePos(1, 1, n, y, arr[y]);

            updateVal(1, 1, n, vx, p[vx]);
            updateVal(1, 1, n, vy, p[vy]);
        }
        else {
            NodeP vp = queryVal(1, 1, n, x, y);
            int l = vp.mnPos;
            int r = vp.mxPos;
            NodeV pv = queryPos(1, 1, n, l, r);
            if (pv.mx - pv.mn == y - x) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}

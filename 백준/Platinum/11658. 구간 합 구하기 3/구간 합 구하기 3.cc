#include <iostream>
using namespace std;

int n, m;
int coord[1025][1025];
int seg[1025 * 4][1025 * 4];

void init_y(int x, int y, int xs, int xe, int ys, int ye) {
	if (ys == ye) {
		if (xs == xe) {
			seg[x][y] = coord[xs][ys];
		}
		else {
			seg[x][y] = seg[x * 2][y] + seg[x * 2 + 1][y];
		}
		return;
	}
	int mid = ys + (ye - ys) / 2;
	init_y(x, y * 2, xs, xe, ys, mid);
	init_y(x, y * 2 + 1, xs, xe, mid + 1, ye);
	seg[x][y] = seg[x][y * 2] + seg[x][y * 2 + 1];
}

void init_x(int x, int s, int e) {
	if (s != e) {
		int mid = s + (e - s) / 2;
		init_x(x * 2, s, mid);
		init_x(x * 2 + 1, mid + 1, e);
	}
	init_y(x, 1, s, e, 1, n);
}

void update_y(int x_node, int y_node, int ys, int ye, int y, int val, int xs, int xe) {
    if (ys == ye) {
        if (xs == xe) {
            seg[x_node][y_node] = val;
        }
        else {
            seg[x_node][y_node] = seg[x_node * 2][y_node] + seg[x_node * 2 + 1][y_node];
        }
    }
    else {
        int ym = (ys + ye) / 2;
        if (y <= ym) {
            update_y(x_node, y_node * 2, ys, ym, y, val, xs, xe);
        }
        else {
            update_y(x_node, y_node * 2 + 1, ym + 1, ye, y, val, xs, xe);
        }
        seg[x_node][y_node] = seg[x_node][y_node * 2] + seg[x_node][y_node * 2 + 1];
    }
}

void update_x(int x_node, int xs, int xe, int x, int y, int val) {
    if (xs != xe) {
        int xm = (xs + xe) / 2;
        if (x <= xm) {
            update_x(x_node * 2, xs, xm, x, y, val);
        }
        else {
            update_x(x_node * 2 + 1, xm + 1, xe, x, y, val);
        }
    }
    update_y(x_node, 1, 1, n, y, val, xs, xe);
}

int query_y(int x_node, int y_node, int ys, int ye, int ly, int ry) {
    if (ly > ye || ry < ys) return 0;
    if (ly <= ys && ye <= ry) {
        return seg[x_node][y_node];
    }
    int ym = (ys + ye) / 2;
    return query_y(x_node, y_node * 2, ys, ym, ly, ry) + query_y(x_node, y_node * 2 + 1, ym + 1, ye, ly, ry);
}

int query_x(int x_node, int xs, int xe, int lx, int rx, int ly, int ry) {
    if (lx > xe || rx < xs) return 0;
    if (lx <= xs && xe <= rx) {
        return query_y(x_node, 1, 1, n, ly, ry);
    }
    int xm = (xs + xe) / 2;
    return query_x(x_node * 2, xs, xm, lx, rx, ly, ry) + query_x(x_node * 2 + 1, xm + 1, xe, lx, rx, ly, ry);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> coord[i][j];
        }
    }

    init_x(1, 1, n);

    for (int i = 0; i < m; i++) {
        int cmd;
        cin >> cmd;

        if (cmd == 0) {
            int x, y, v;
            cin >> x >> y >> v;
            update_x(1, 1, n, x, y, v);
        }
        else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << query_x(1, 1, n, x1, x2, y1, y2) << '\n';
        }
    }

    return 0;
}
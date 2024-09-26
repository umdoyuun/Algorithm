#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////
/*
 * Author : jinhan814
 * Date : 2021-04-16
 * Source : https://blog.naver.com/jinhan814/222266396476
 * Description : FastIO implementation for cin, cout.
 */
constexpr int SZ = 1 << 20;

class INPUT {
private:
	char read_buf[SZ];
	int read_idx, next_idx;
	bool __END_FLAG__, __GETLINE_FLAG__;
public:
	explicit operator bool() { return !__END_FLAG__; }
	bool is_blank(char c) { return c == ' ' || c == '\n'; }
	bool is_end(char c) { return c == '\0'; }
	char _readChar() {
		if (read_idx == next_idx) {
			next_idx = fread(read_buf, sizeof(char), SZ, stdin);
			if (next_idx == 0) return 0;
			read_idx = 0;
		}
		return read_buf[read_idx++];
	}
	char readChar() {
		char ret = _readChar();
		while (is_blank(ret)) ret = _readChar();
		return ret;
	}
	template<typename T> T readInt() {
		T ret = 0; char cur = _readChar(); bool flag = 0;
		while (is_blank(cur)) cur = _readChar();
		if (cur == '-') flag = 1, cur = _readChar();
		while (!is_blank(cur) && !is_end(cur)) ret = 10 * ret + cur - '0', cur = _readChar();
		if (is_end(cur)) __END_FLAG__ = 1;
		return flag ? -ret : ret;
	}
	string readString() {
		string ret; char cur = _readChar();
		while (is_blank(cur)) cur = _readChar();
		while (!is_blank(cur) && !is_end(cur)) ret.push_back(cur), cur = _readChar();
		if (is_end(cur)) __END_FLAG__ = 1;
		return ret;
	}
	double readDouble() {
		string ret = readString();
		return stod(ret);
	}
	string getline() {
		string ret; char cur = _readChar();
		while (cur != '\n' && !is_end(cur)) ret.push_back(cur), cur = _readChar();
		if (__GETLINE_FLAG__) __END_FLAG__ = 1;
		if (is_end(cur)) __GETLINE_FLAG__ = 1;
		return ret;
	}
	friend INPUT& getline(INPUT& in, string& s) { s = in.getline(); return in; }
} _in;

class OUTPUT {
private:
	char write_buf[SZ];
	int write_idx;
public:
	~OUTPUT() { bflush(); }
	void bflush() {
		fwrite(write_buf, sizeof(char), write_idx, stdout);
		write_idx = 0;
	}
	void writeChar(char c) {
		if (write_idx == SZ) bflush();
		write_buf[write_idx++] = c;
	}
	template<typename T> int getSize(T n) {
		int ret = 1;
		if (n < 0) n = -n;
		while (n >= 10) ret++, n /= 10;
		return ret;
	}
	template<typename T> void writeInt(T n) {
		int sz = getSize(n);
		if (write_idx + sz >= SZ) bflush();
		if (n < 0) write_buf[write_idx++] = '-', n = -n;
		for (int i = sz - 1; i >= 0; i--) write_buf[write_idx + i] = n % 10 + '0', n /= 10;
		write_idx += sz;
	}
	void writeString(string s) { for (auto& c : s) writeChar(c); }
	void writeDouble(double d) { writeString(to_string(d)); }
} _out;

/* operators */
INPUT& operator>> (INPUT& in, char& i) { i = in.readChar(); return in; }
INPUT& operator>> (INPUT& in, string& i) { i = in.readString(); return in; }
template<typename T, typename std::enable_if_t<is_integral_v<T>>* = nullptr>
INPUT& operator>> (INPUT& in, T& i) { i = in.readInt<T>(); return in; }
template<typename T, typename std::enable_if_t<is_floating_point_v<T>>* = nullptr>
INPUT& operator>> (INPUT& in, T& i) { i = in.readDouble(); return in; }
OUTPUT& operator<< (OUTPUT& out, char i) { out.writeChar(i); return out; }
OUTPUT& operator<< (OUTPUT& out, string i) { out.writeString(i); return out; }
template<typename T, typename std::enable_if_t<is_integral_v<T>>* = nullptr>
OUTPUT& operator<< (OUTPUT& out, T i) { out.writeInt<T>(i); return out; }
template<typename T, typename std::enable_if_t<is_floating_point_v<T>>* = nullptr>
OUTPUT& operator<< (OUTPUT& out, T i) { out.writeDouble(i); return out; }

/* macros */
#define fastio 1
#define cin _in
#define cout _out
#define istream INPUT
#define ostream OUTPUT
/////////////////////////////////////////////////////////////////////////////////////////////

long long arr[100001];
struct node {
	long long sum, mx, mn;
};
node seg[100002 * 4];
long long lazy[100002 * 4][2]; // 0: sum 1: sqrt

void init(int x, int s, int e) {
	lazy[x][0] = 0;
	lazy[x][1] = 0;
	if (s == e) {
		seg[x] = { arr[s], arr[s], arr[s] };
		return;
	}
	int mid = s + (e - s) / 2;
	init(x * 2, s, mid);
	init(x * 2 + 1, mid + 1, e);
	seg[x] = { seg[x * 2].sum + seg[x * 2 + 1].sum, max(seg[x * 2].mx, seg[x * 2 + 1].mx), min(seg[x * 2].mn, seg[x * 2 + 1].mn) };
	return;
}

void lazy_update(int x, int s, int e) {
	if (!lazy[x][0] && !lazy[x][1]) return;
	if (!lazy[x][1]) {
		seg[x].sum += lazy[x][0] * (e - s + 1);
		seg[x].mn += lazy[x][0];
		seg[x].mx += lazy[x][0];
		if (s != e) {
			lazy[x * 2][0] += lazy[x][0];
			lazy[x * 2 + 1][0] += lazy[x][0];
		}
		lazy[x][0] = 0;
	}
	else {
		seg[x].sum = (lazy[x][1] + lazy[x][0]) * (e - s + 1);
		seg[x].mn = lazy[x][1] + lazy[x][0];
		seg[x].mx = lazy[x][1] + lazy[x][0];
		if (s != e) {
			lazy[x * 2][0] = lazy[x][0];
			lazy[x * 2][1] = lazy[x][1];
			lazy[x * 2 + 1][0] = lazy[x][0];
			lazy[x * 2 + 1][1] = lazy[x][1];
		}
		lazy[x][1] = 0;
		lazy[x][0] = 0;
	}
	return;
}

void update_sum(int x, int s, int e, int l, int r, long long diff) {
	lazy_update(x, s, e);
	if (r < s || l > e) return;
	if (l <= s && e <= r) {
		lazy[x][0] = diff;
		lazy_update(x, s, e);
		return;
	}
	int mid = s + (e - s) / 2;
	update_sum(x * 2, s, mid, l, r, diff);
	update_sum(x * 2 + 1, mid + 1, e, l, r, diff);
	seg[x] = { seg[x * 2].sum + seg[x * 2 + 1].sum, max(seg[x * 2].mx, seg[x * 2 + 1].mx), min(seg[x * 2].mn, seg[x * 2 + 1].mn) };
	return;
}

void update_sqrt(int x, int s, int e, int l, int r) {
	lazy_update(x, s, e);
	if (r < s || l > e) return;
	if (l <= s && e <= r) {
		if (floor(sqrt(seg[x].mx)) == floor(sqrt(seg[x].mn))) {
			lazy[x][1] = floor(sqrt(seg[x].mx));
			lazy_update(x, s, e);
			return;
		}
		if (seg[x].mn + 1 == seg[x].mx) {
			lazy[x][0] = sqrt(seg[x].mx) - seg[x].mx;
			lazy_update(x, s, e);
			return;
		}
	}
	int mid = s + (e - s) / 2;
	update_sqrt(x * 2, s, mid, l, r);
	update_sqrt(x * 2 + 1, mid + 1, e, l, r);
	seg[x] = { seg[x * 2].sum + seg[x * 2 + 1].sum, max(seg[x * 2].mx, seg[x * 2 + 1].mx), min(seg[x * 2].mn, seg[x * 2 + 1].mn) };
	return;
}

long long query(int x, int s, int e, int l, int r) {
	lazy_update(x, s, e);
	if (r < s || l > e) return 0;
	if (l <= s && e <= r) {
		return seg[x].sum;
	}
	int mid = s + (e - s) / 2;
	return query(x * 2, s, mid, l, r) + query(x * 2 + 1, mid + 1, e, l, r);
}

int main() {
	fastio;
	int n, m;
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		//memset(seg, 0, sizeof(seg));
		//memset(lazy, 0, sizeof(lazy));
		for (register int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		init(1, 0, n - 1);
		for (register int i = 0; i < m; i++) {
			int cmd, l, r, x;
			cin >> cmd >> l >> r;
			l--, r--;
			if (cmd == 3) {
				cin >> x;
				update_sum(1, 0, n - 1, l, r, x);
			}
			else if (cmd == 1) {
				update_sqrt(1, 0, n - 1, l, r);
			}
			else {
				long long res = query(1, 0, n - 1, l, r);
				cout << res << '\n';
			}
		}
	}
	return 0;
}
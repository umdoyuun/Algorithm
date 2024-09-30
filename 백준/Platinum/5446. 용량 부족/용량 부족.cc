#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////
/*
 * Author : jinhan814
 * Date : 2021-05-06
 * Source : https://blog.naver.com/jinhan814/222266396476
 * Description : FastIO implementation for cin, cout. (mmap ver.)
 */
constexpr int SZ = 1 << 20;

class INPUT {
private:
	char* p;
	bool __END_FLAG__, __GETLINE_FLAG__;
public:
	explicit operator bool() { return !__END_FLAG__; }
	INPUT() {
		struct stat st; fstat(0, &st);
		p = (char*)mmap(0, st.st_size, PROT_READ, MAP_SHARED, 0, 0);
	}
	bool IsBlank(char c) { return c == ' ' || c == '\n'; }
	bool IsEnd(char c) { return c == '\0'; }
	char _ReadChar() { return *p++; }
	char ReadChar() {
		char ret = _ReadChar();
		for (; IsBlank(ret); ret = _ReadChar());
		return ret;
	}
	template<typename T> T ReadInt() {
		T ret = 0; char cur = _ReadChar(); bool flag = 0;
		for (; IsBlank(cur); cur = _ReadChar());
		if (cur == '-') flag = 1, cur = _ReadChar();
		for (; !IsBlank(cur) && !IsEnd(cur); cur = _ReadChar()) ret = 10 * ret + (cur & 15);
		if (IsEnd(cur)) __END_FLAG__ = 1;
		return flag ? -ret : ret;
	}
	string ReadString() {
		string ret; char cur = _ReadChar();
		for (; IsBlank(cur); cur = _ReadChar());
		for (; !IsBlank(cur) && !IsEnd(cur); cur = _ReadChar()) ret.push_back(cur);
		if (IsEnd(cur)) __END_FLAG__ = 1;
		return ret;
	}
	double ReadDouble() {
		string ret = ReadString();
		return stod(ret);
	}
	string getline() {
		string ret; char cur = _ReadChar();
		for (; cur != '\n' && !IsEnd(cur); cur = _ReadChar()) ret.push_back(cur);
		if (__GETLINE_FLAG__) __END_FLAG__ = 1;
		if (IsEnd(cur)) __GETLINE_FLAG__ = 1;
		return ret;
	}
	friend INPUT& getline(INPUT& in, string& s) { s = in.getline(); return in; }
} _in;

class OUTPUT {
private:
	char write_buf[SZ];
	int write_idx;
public:
	~OUTPUT() { Flush(); }
	explicit operator bool() { return 1; }
	void Flush() {
		write(1, write_buf, write_idx);
		write_idx = 0;
	}
	void WriteChar(char c) {
		if (write_idx == SZ) Flush();
		write_buf[write_idx++] = c;
	}
	template<typename T> int GetSize(T n) {
		int ret = 1;
		for (n = n >= 0 ? n : -n; n >= 10; n /= 10) ret++;
		return ret;
	}
	template<typename T> void WriteInt(T n) {
		int sz = GetSize(n);
		if (write_idx + sz >= SZ) Flush();
		if (n < 0) write_buf[write_idx++] = '-', n = -n;
		for (int i = sz; i-- > 0; n /= 10) write_buf[write_idx + i] = n % 10 | 48;
		write_idx += sz;
	}
	void WriteString(string s) { for (auto& c : s) WriteChar(c); }
	void WriteDouble(double d) { WriteString(to_string(d)); }
} _out;

/* operators */
INPUT& operator>> (INPUT& in, char& i) { i = in.ReadChar(); return in; }
INPUT& operator>> (INPUT& in, string& i) { i = in.ReadString(); return in; }
template<typename T, typename std::enable_if_t<is_arithmetic_v<T>>* = nullptr>
INPUT& operator>> (INPUT& in, T& i) {
	if constexpr (is_floating_point_v<T>) i = in.ReadDouble();
	else if constexpr (is_integral_v<T>) i = in.ReadInt<T>(); return in;
}

OUTPUT& operator<< (OUTPUT& out, char i) { out.WriteChar(i); return out; }
OUTPUT& operator<< (OUTPUT& out, string i) { out.WriteString(i); return out; }
template<typename T, typename std::enable_if_t<is_arithmetic_v<T>>* = nullptr>
OUTPUT& operator<< (OUTPUT& out, T i) {
	if constexpr (is_floating_point_v<T>) out.WriteDouble(i);
	else if constexpr (is_integral_v<T>) out.WriteInt<T>(i); return out;
}

/* macros */
#define fastio 1
#define cin _in
#define cout _out
#define istream INPUT
#define ostream OUTPUT
/////////////////////////////////////////////////////////////////////////////////////////////

int n, m, res;

struct Trie {
	int cnt = 0;
	bool isEnd = false;
	map<char, Trie*> child;
};

Trie* root;
Trie pool[100000];
int p_cnt;

Trie* new_node() {
	pool[p_cnt].cnt = 0;
	pool[p_cnt].isEnd = false;
	pool[p_cnt].child.clear();
	return &pool[p_cnt++];
}

void init() {
	p_cnt = 0;
	root = new_node();
	res = 0;
}

void insert_trie(string str) {
	Trie* cur = root;
	int s = str.size();
	for (int i = 0; i < s; i++) {
		char c = str[i];
		if (cur->child.find(c) == cur->child.end()) {
			cur->child[c] = new_node();
		}
		cur = cur->child[c];
	}
	cur->isEnd = true;
	return;
}

void set_trie(string str) {
	Trie* cur = root;
	int s = str.size();
	for (int i = 0; i < s; i++) {
		char c = str[i];
		cur->cnt++;
		if (cur->child.find(c) == cur->child.end()) {
			cur->child[c] = new_node();
		}
		cur = cur->child[c];
	}
	cur->cnt++;
}

void check(Trie* cur) {
	if (cur->cnt == 0) {
		res++;
		return;
	}
	else if(cur->isEnd){
		res++;
	}
	for (auto iter = cur->child.begin(); iter != cur->child.end(); iter++) {
		check(iter->second);
	}
	return;
}

int main() {
	fastio;
	int T;
	cin >> T;
	while (T--) {
		init();
		cin >> n;
		string str;
		for (int i = 0; i < n; i++) {
			cin >> str;
			insert_trie(str);
		}
		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> str;
			set_trie(str);
		}
		check(root);
		cout << res << '\n';
	}
	return 0;
}
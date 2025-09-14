#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, string> mp;
string s;
int main() {
	mp.insert(make_pair("CU", "see you"));
	mp.insert(make_pair(":-)", "I’m happy"));
	mp.insert(make_pair(":-(", "I’m unhappy"));
	mp.insert(make_pair(";-)", "wink"));
	mp.insert(make_pair(":-P", "stick out my tongue"));
	mp.insert(make_pair("(~.~)", "sleepy"));
	mp.insert(make_pair("TA", "totally awesome"));
	mp.insert(make_pair("CCC", "Canadian Computing Competition"));
	mp.insert(make_pair("CUZ", "because"));
	mp.insert(make_pair("TY", "thank-you"));
	mp.insert(make_pair("YW", "you’re welcome"));
	mp.insert(make_pair("TTYL", "talk to you later"));
	
	while (getline(cin, s)) {
		if (mp.count(s)) cout << mp[s] << '\n';
		else cout << s << '\n';
	}
}
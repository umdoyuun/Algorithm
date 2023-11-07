#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int cnt[101];
int result, max_cnt;
vector<int> v;

void init(){
	memset(cnt, 0, sizeof(cnt));
    result, max_cnt = 0;
    v.clear();
}

int main(){
 	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
    	init();
        int a;
        cin >> a;
        for(int i = 0; i < 1000; i++){
        	int x;
            cin >> x;
            cnt[x]++;
            if(cnt[x] == max_cnt){
            	v.push_back(x);
            }
            else if(cnt[x] > max_cnt){
            	v.clear();
                v.push_back(x);
                max_cnt = cnt[x];
            }
        }
        sort(v.begin(), v.end());
        cout << '#' << tc << ' ' << v[v.size()-1] << '\n';
    }
    return 0;
}
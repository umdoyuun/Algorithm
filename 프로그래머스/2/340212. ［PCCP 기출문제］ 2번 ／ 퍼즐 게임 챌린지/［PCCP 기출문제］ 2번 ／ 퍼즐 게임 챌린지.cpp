#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int n;
int mx;
vector<pair<int, int>> v;
long long func(int x){
    long long t = 0, prev = 0;
    for(int i = 0 ; i < n; i++){
        int level = v[i].first;
        long long c_t = v[i].second;
        if(level <= x){
            t += c_t;
        }
        else{
            t += (c_t + prev) * (level - x) + c_t;
        }
        prev = c_t;
        //cout << ' ' << t << ' ' << level - x << '\n';
    }
    //cout << x << ' ' << t << '\n';
    return t;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    n = diffs.size();
    v.resize(n);
    for(int i = 0; i < n; i++){
        int x = diffs[i];
        int t = times[i];
        mx = max(x, mx);
        v[i] = {x, t};
    }
    int s = 1, e = mx;
    while(s <= e){
        int mid = s + (e - s) / 2;
        if(func(mid) <= limit){
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }
    return s;
}
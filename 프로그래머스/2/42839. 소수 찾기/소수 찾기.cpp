#include <string>
#include <vector>
#include <cmath>
#include <string>
#include <unordered_map>
using namespace std;

bool prime_num[10000000];
bool check[10000000];

unordered_map<int, bool> visit;
int n, res;
string str;

void eratostenes(){
    int mx_size = pow(10, n);
    for(int i = 2; i < 10000000; i++){
        if(!check[i]){
            prime_num[i] = true;
            for(int j = i + i; j < 10000000; j += i){
                check[j] = true;
            }
        }
    }
}

void dfs(string x, int d, vector<bool> dat){
    if(d > n) return;
    if(x != "" && prime_num[stoi(x)] && !visit[stoi(x)]) res++;
    if(x != "") visit[stoi(x)] = true;
    for(int i = 0; i < n; i++){
        if(!dat[i]) continue;
        string y = x;
        y += str[i];
        dat[i] = false;
        dfs(y, d + 1, dat);
        dat[i] = true;
    }
}

int solution(string numbers) {
    int answer = 0;
    n = numbers.size();
    str = numbers;
    vector<bool> dat;
    for(int i = 0; i < n; i++){
        dat.push_back(true);
    }
    eratostenes();
    dfs("", 0, dat);
    answer = res;
    return answer;
}
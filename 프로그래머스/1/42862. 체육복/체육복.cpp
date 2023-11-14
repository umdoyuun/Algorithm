#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool check[31];
int dx[2] = {-1, 1};
int N;

bool func(int x){
    for(int i = 0; i < 2; i++){
        int nx = x + dx[i];
        if(nx < 1 || nx > N) continue;
        if(check[nx]){
            check[nx] = false;
            return true;
        }
    }
    return false;
}

int solution(int n, vector<int> lost, vector<int> reserve) {
    N = n;
    int answer = n - lost.size();
    for(int i = 0; i < reserve.size(); i++){
        check[reserve[i]] = true;
    }
    for(int i = 0 ; i < lost.size(); i++){
        if(check[lost[i]]){
            answer++;
            check[lost[i]] = false;
            lost[i] = -1;
        }
    }
    sort(lost.begin(), lost.end());
    for(int i = 0; i < lost.size(); i++){
        if(lost[i] < 0) continue;
        if(func(lost[i])) answer++;
    }
    return answer;
}
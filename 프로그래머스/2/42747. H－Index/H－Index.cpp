#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int x, int y){
    return x > y;
}

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), compare);
    for(int i = 0; i < citations.size();i++){
        if((i+1) <= citations[i]){
            answer = i+1;
        }
        else break;
    }
    return answer;
}
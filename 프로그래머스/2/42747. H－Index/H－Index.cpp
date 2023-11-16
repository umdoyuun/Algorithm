#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int x, int y){
    return x > y;
}

int solution(vector<int> citations) {
    int answer = 0;
    int h1, h2, h;
    sort(citations.begin(), citations.end(), compare);
    for(int i = 0; i < citations.size(); i++){
        h1 = i + 1;
        h2 = citations[i];
        h = min(h1, h2);
        answer = max(h, answer);
    }
    return answer;
}
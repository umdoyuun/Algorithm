#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int student2[10] = {2, 1, 2, 3, 2, 4, 2, 5};
int student3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    int scores[3] = {0,};
    vector<int> answer;
    for(int i = 0; i < answers.size(); i++){
        int tar = answers[i];
        if(i % 5 + 1 == tar) scores[0]++;
        if(student2[i % 8] == tar) scores[1]++;
        if(student3[i % 10] == tar) scores[2]++;
    }
    int mx = scores[0];
    answer.push_back(1);
    for(int i = 1; i < 3; i++){
        if(mx == scores[i]) answer.push_back(i + 1);
        if(mx < scores[i]){
            answer.clear();
            mx = scores[i];
            answer.push_back(i + 1);
        }
    }
    return answer;
}
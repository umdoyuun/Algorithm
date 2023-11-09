#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string x, string y){
    return x+y > y+x;
}

//void print(string answer){
//    cout << answer << '\n';
//}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    for(int i = 0; i < numbers.size(); i++){
        v.push_back(to_string(numbers[i]));
    }
    sort(v.begin(), v.end(), compare);
    for(int i = 0; i < v.size(); i++)
        answer += v[i];
    //print(answer);
    if(answer[0] == '0')
        answer = "0";
    return answer;
}
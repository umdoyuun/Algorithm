#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool graph[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    for(int i = 0; i < results.size(); i++)
        graph[results[i][0]][results[i][1]] = true;
    
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if (graph[i][k] == true && graph[k][j] == true)
                    graph[i][j] = true;
    
    for(int i = 1; i <= n; i++)
    {
        int count = 0;
        for(int j = 1; j <= n; j++)
            if (graph[i][j] == true || graph[j][i] == true)
                count++;
        if (count == n - 1)
            answer++;
    }
    
    return answer;
}
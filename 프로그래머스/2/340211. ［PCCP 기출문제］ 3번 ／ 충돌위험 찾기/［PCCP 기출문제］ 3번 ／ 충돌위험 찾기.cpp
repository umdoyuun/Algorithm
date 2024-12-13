#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int n, mx;
vector<pair<int, int>> v[101];
int visit[101][101];
pair<int, int> p[101];

void make_route(int robot, int sx, int sy, int ex, int ey){
    int x = sx;
    int y = sy;
    while(x != ex || y != ey){
        if(x > ex){
            x--;
        }
        else if(x < ex){
            x++;
        }
        else if(y > ey){
            y--;
        }
        else if(y < ey){
            y++;
        }
        v[robot].push_back({x, y});
    }
    return;
}

void print(){
    cout << '\n';
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cout << visit[i][j] << ' ';
        }
        cout << '\n';
    }
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    n = points.size();
    for(int i = 0; i < points.size(); i++){
        int x = points[i][0];
        int y = points[i][1];
        p[i + 1] = {x , y};
    }
    int m = routes.size();
    for(int i = 0; i < routes.size(); i++){
        int c = routes[i][0];
        v[i].push_back({p[c].first, p[c].second});
        for(int j = 1; j < routes[i].size(); j++){
            int t = routes[i][j];
            make_route(i, p[c].first, p[c].second, p[t].first, p[t].second);
            c = t;
        }
        mx = max(mx, int(v[i].size()));
        //for(int j = 0; j < v[i].size(); j++){
        //    cout << v[i][j].first << ',' << v[i][j].second << " / ";
        //}
        //cout << '\n';
    }
    cout << mx << '\n';
    for(int i = 0; i < mx; i++){
        memset(visit, 0, sizeof(visit));
        for(int j = 0; j < m; j++){
            if(v[j].size() <= i) continue;
            int x = v[j][i].first;
            int y = v[j][i].second;
            //cout << j << ' ' <<  x << ' ' << y << '\n';
            visit[x][y]++;
            if(visit[x][y] == 2) answer++;
        }
        //print();
    }
    return answer;
}
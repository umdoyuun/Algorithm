#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <sstream>
using namespace std;
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };
int N;
int arr[20][20];
int arr2[20][20];
int Max = 0;

int cc = 0;
int curMax[10];
int block = 0; //블록 개수
int MaxB;
int st;
//int pre[20][20];
int tmpMax;
bool Col;
bool Row;

//unordered_set<string> vis;



bool move(int ind, int arr2[][20]) {
    bool moved = false;
    Col = false;
    Row = false;
    if (ind == 0) { //위
        for (int j = 0; j < N; j++) {
            int tmp = -1;
            for (int i = 1; i < N; i++) {
                if (arr2[i][j] == 0) continue;
                int ind = i;
                while (ind > 0) {
                    if (arr2[ind - 1][j] != 0) { //블록 있으면 더이상 못감 
                        break;
                    }
                    ind--;

                }
                if (arr2[ind][j] == 0) { //이동
                    arr2[ind][j] = arr2[i][j];
                    arr2[i][j] = 0;
                    moved = true; //이동 여부 체크 
                    Col = true;
                }
                if (ind == 0) continue;
                if (arr2[ind - 1][j] == arr2[ind][j] && ind - 1 > tmp) { //바로 위랑 같으면 합쳐짐
                    arr2[ind - 1][j] = arr2[ind - 1][j] * 2;
                    arr2[ind][j] = 0;
                    //vis[ind-1][j]=1;

                    tmp = ind - 1; //합쳐진 블록 위치
                    moved = true;
                    Col = true;

                }
            }
        }
        //fill(&vis[0][0],&vis[0][0]+20*20,0);
    }

    else if (ind == 1) { //오른쪽
        for (int i = 0; i < N; i++) {
            int tmp = N;
            for (int j = N - 2; j >= 0; j--) {
                if (arr2[i][j] == 0) continue;
                int ind = j;
                while (ind < N - 1) {
                    if (arr2[i][ind + 1] != 0) { //블록 있으면 더이상 못감 
                        break;
                    }
                    ind++;

                }
                if (arr2[i][ind] == 0) { //이동
                    arr2[i][ind] = arr2[i][j];
                    arr2[i][j] = 0;
                    moved = true;
                    Row = true;

                }
                if (ind == N - 1) continue;
                if (arr2[i][ind + 1] == arr2[i][ind] && ind + 1 < tmp) { //바로 위랑 같으면 합쳐짐
                    arr2[i][ind + 1] = arr2[i][ind + 1] * 2;
                    arr2[i][ind] = 0;
                    tmp = ind + 1; //합쳐진 블록 위치
                    moved = true;
                    Row = true;

                }
            }
        }
    }
    else if (ind == 2) { //아래
        for (int j = 0; j < N; j++) {
            int tmp = N;
            for (int i = N - 1; i >= 0; i--) {
                if (arr2[i][j] == 0) continue;
                int ind = i;
                while (ind < N - 1) {
                    if (arr2[ind + 1][j] != 0) { //블록 있으면 더이상 못감 
                        break;
                    }
                    ind++;

                }
                if (arr2[ind][j] == 0) { //이동
                    arr2[ind][j] = arr2[i][j];
                    arr2[i][j] = 0;
                    moved = true;
                    Col = true;

                }
                if (ind == N - 1) continue;
                if (arr2[ind + 1][j] == arr2[ind][j] && ind + 1 < tmp) { //바로 위랑 같으면 합쳐짐
                    arr2[ind + 1][j] = arr2[ind + 1][j] * 2;
                    arr2[ind][j] = 0;
                    tmp = ind + 1; //합쳐진 블록 위치
                    moved = true;
                    Col = true;

                }
            }
        }
    }
    else if (ind == 3) { //왼
        for (int i = 0; i < N; i++) {
            int tmp = -1;
            for (int j = 1; j < N; j++) {
                if (arr2[i][j] == 0) continue;
                int ind = j;
                while (ind > 0) {
                    if (arr2[i][ind - 1] != 0) { //블록 있으면 더이상 못감 
                        break;
                    }
                    ind--;

                }
                if (arr2[i][ind] == 0) { //이동
                    arr2[i][ind] = arr2[i][j];
                    arr2[i][j] = 0;
                    moved = true;
                    Row = true;

                }
                if (ind == 0) continue;
                if (arr2[i][ind - 1] == arr2[i][ind] && ind - 1 > tmp) { //바로 위랑 같으면 합쳐짐
                    arr2[i][ind - 1] = arr2[i][ind - 1] * 2;
                    arr2[i][ind] = 0;
                    tmp = ind - 1; //합쳐진 블록 위치
                    moved = true;
                    Row = true;

                }
            }
        }
    }
    tmpMax = 0;
    /*for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(pre[i][j] != arr2[i][j]) ;
        }
    }*/
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Max = max(Max, arr2[i][j]);
            tmpMax = max(tmpMax, arr2[i][j]);
        }
    }

    return moved;
}
void func(int cnt, int arr2[][20]) {
    if (cnt == 10) {
        //cc++;
        /*for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                Max = max(Max, arr2[i][j]);
            }
        }*/
        return;
    }
    //cout << tmpMax << ' ' << Max << '\n';
    if ((tmpMax) && (tmpMax << (10 - cnt)) <= Max) return;

    //string cur = toString(arr2);
    //if (vis.find(cur) != vis.end()) return;
    //vis.insert(cur);

    for (int i = 0; i < 4; i++) {
        /*if (!Col && cnt != 0) {
            if (i % 2 == 0) continue;
        }
        if (!Row && cnt != 0) {
            if (i % 2 == 1) continue;

        }*/
        int tmpArr[20][20];
        copy(&arr2[0][0], &arr2[0][0] + 20 * 20, &tmpArr[0][0]); //이거 안해줘서 틀림!!! 
        if (move(i, tmpArr)) {
            /*if (cnt == 8 && tmpMax < Max / 2) continue;
            else if (cnt == 7 && tmpMax < Max / 4) continue;*/
            //if(Max-tmpMax>(10-cnt-1)*1024) continue;
            //curMax[cnt] = tmpMax;
            func(cnt + 1, tmpArr);

        }
        //if (Max >= st) return;
        /*else if(cnt==8&& cur <Max/2) return;
        else if (cnt == 7 && cur < Max / 4) return;*/



    }

}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if (arr[i][j] > 0) {
                //block++;
                Max = max(Max, arr[i][j]); //블록의 최대값 
            }
        }
    }
    //st = MaxB * block;
    copy(&arr[0][0], &arr[0][0] + 20 * 20, &arr2[0][0]);

    func(0, arr2);
    cout << Max << '\n';

}
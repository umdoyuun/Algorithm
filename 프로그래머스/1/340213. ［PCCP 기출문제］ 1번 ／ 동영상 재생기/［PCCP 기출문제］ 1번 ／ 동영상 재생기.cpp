#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    string cur = pos;
    int cur_m = stoi(pos.substr(0, 2));
    int cur_s = stoi(pos.substr(3));
    int op_s_m = stoi(op_start.substr(0, 2));
    int op_s_s = stoi(op_start.substr(3));
    int op_e_m = stoi(op_end.substr(0, 2));
    int op_e_s = stoi(op_end.substr(3));
    int v_l_m = stoi(video_len.substr(0, 2));
    int v_l_s = stoi(video_len.substr(3));
    for(string cmd : commands){
        if(cur_m > op_s_m && cur_m < op_e_m){
            cur_m = op_e_m;
            cur_s = op_e_s;
        }
        else if(cur_m == op_s_m && cur_m == op_e_m && cur_s >= op_s_s && cur_s <= op_e_s){
            cur_m = op_e_m;
            cur_s = op_e_s;
        }
        else if(op_s_m != op_e_m && cur_m == op_s_m && cur_s >= op_s_s){
            cur_m = op_e_m;
            cur_s = op_e_s;
        }
        else if(op_s_m != op_e_m && cur_m == op_e_m && cur_s <= op_e_s){
            cur_m = op_e_m;
            cur_s = op_e_s;
        }
        if(cmd == "next"){
            cur_s += 10;
            if(cur_s >= 60){
                cur_s -= 60;
                cur_m += 1;
            }
        }
        else if(cmd == "prev"){
            cur_s -= 10;
            if(cur_s < 0){
                cur_s +=60;
                cur_m -= 1;
            }
        }

        if(cur_m < 0){
            cur_m = 0;
            cur_s = 0;
        }
        else if(cur_m > v_l_m || (cur_m == v_l_m && cur_s >= v_l_s)){
            cur_m = v_l_m;
            cur_s = v_l_s;
        }  


    }
    if(cur_m > op_s_m && cur_m < op_e_m){
        cur_m = op_e_m;
        cur_s = op_e_s;
    }
    else if(cur_m == op_s_m && cur_m == op_e_m && cur_s >= op_s_s && cur_s <= op_e_s){
        cur_m = op_e_m;
        cur_s = op_e_s;
    }
    else if(op_s_m != op_e_m && cur_m == op_s_m && cur_s >= op_s_s){
        cur_m = op_e_m;
        cur_s = op_e_s;
    }
    else if(op_s_m != op_e_m && cur_m == op_e_m && cur_s <= op_e_s){
        cur_m = op_e_m;
        cur_s = op_e_s;
    }

    if(cur_m < 10) answer += "0";
    answer += to_string(cur_m);
    answer += ":";
    if(cur_s < 10) answer += "0";
    answer += to_string(cur_s);
    return answer;
}
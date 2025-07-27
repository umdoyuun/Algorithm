#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, string> um;

int main(){
    um["Algorithm"] = "204";
    um["DataAnalysis"] = "207";
    um["ArtificialIntelligence"] = "302";
    um["CyberSecurity"] = "B101";
    um["Network"] = "303";
    um["Startup"] = "501";
    um["TestStrategy"] = "105";
    
    int n;
    cin >> n;
    while(n--){
        string str;
        cin >> str;
        cout << um[str] << '\n';
    }
}

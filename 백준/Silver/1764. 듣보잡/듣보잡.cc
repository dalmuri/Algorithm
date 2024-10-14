#include <string>
#include <iostream>
#include <vector>
#include <map>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, m;
    cin >> n >> m;

    map<string, int> cnt;

    string name;
    for(int i = 0; i < n; i++){
        cin >> name;

        cnt[name]++;
    }
    for(int i = 0; i < m; i++){
        cin >> name;
        cnt[name]++;
    }

    vector<string> answer;

    for(auto iter = cnt.begin(); iter != cnt.end(); iter++){
        if((*iter).second == 2) answer.push_back((*iter).first);
    }

    cout << answer.size() << "\n";
    for(string str : answer) cout << str << "\n";

    return 0;
}
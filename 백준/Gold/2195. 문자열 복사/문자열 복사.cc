#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int copy_size(string& s, string& p, int start){
    int result = 0;
    for(int i = 0; i < s.size(); ++i){
        int j = 0;
        for(; i + j < s.size() && start + j < p.size(); ++j){
            if(s[i + j] != p[start + j]) break;
        }
        result = max(result, j);
    }
    return result;
}

int main(){
    FASTIO

    string s, p;
    cin >> s >> p;

    int answer = 0;
    for(int i = 0; i < p.size();){
        i += copy_size(s, p, i);
        answer++;
    }

    cout << answer;

    return 0;
}
#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    string str;
    cin >> str;

    vector<bool> used(str.size(), false);

    int answer = 0;
    queue<int> q;
    for(int i = 0; i < str.size(); ++i){
        if(str[i] == 'B') q.push(i);
        else if(str[i] == 'C' && q.size() > 0){
            used[q.front()] = true;
            q.pop();
            answer++;
        }
    }
    for(int i = 0, cnt_a = 0; i < str.size(); ++i){
        if(str[i] == 'A') cnt_a++;
        else if(str[i] == 'B' && !used[i] && cnt_a > 0){
            cnt_a--;
            answer++;
        }
    }

    cout << answer;

    return 0;
}
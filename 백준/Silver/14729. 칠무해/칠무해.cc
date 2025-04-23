#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

struct cmp{
    bool operator()(string a, string b){
        if(a.size() != b.size()) return a.size() < b.size();
        return a < b;
    }
};

int main(){
    FASTIO

    int n;
    cin >> n;

    cmp tmp;
    priority_queue<string, vector<string>, cmp> pq;
    for(int i = 0; i < n; ++i){
        string score;
        cin >> score;

        if(pq.size() < 7) pq.push(score);
        else{
            if(tmp(score, pq.top())){
                pq.pop();
                pq.push(score);
            }
        }
    }

    vector<string> answer(7);
    for(int i = 6; i >= 0; --i) answer[i] = pq.top(), pq.pop();
    for(int i = 0; i < 7; ++i) cout << answer[i] << "\n";

    return 0;
}
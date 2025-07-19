#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, m;
    cin >> n >> m;

    int answer = 0;
    vector<int> cakes_10;
    vector<int> cakes_other;
    for(int i = 0, cake; i < n; ++i){
        cin >> cake;
        if(cake < 10) continue;
        if(cake == 10) { answer++; continue; }
        
        if(cake % 10) cakes_other.push_back(cake);
        else cakes_10.push_back(cake);
    }

    sort(cakes_10.begin(), cakes_10.end());

    for(int i = 0; i < cakes_10.size() && m > 0; ++i){
        int cut = cakes_10[i] / 10 - 1;
        if(m >= cut){
            answer += cut + 1;
            m -= cut;
        }
        else{
            answer += m;
            m = 0;
        }
    }

    for(int i = 0; i < cakes_other.size() && m > 0; ++i){
        int cut = min(cakes_other[i] / 10, m);
        answer += cut;
        m -= cut;
    }

    cout << answer;

    return 0;
}
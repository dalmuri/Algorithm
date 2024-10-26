#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, k;
    cin >> n >> k;

    vector<vector<int>> jewels(n);
    for(int i = 0; i < n; i++){
        int m, v;
        cin >> m >> v;
        jewels[i] = {m, v};
    }

    vector<int> bags(k);
    for(int i = 0; i < k; i++) cin >> bags[i];

    sort(jewels.begin(), jewels.end());
    sort(bags.begin(), bags.end());

    priority_queue<int> pq;
    int idx = 0;
    long long answer = 0;
    for(int bag : bags){
        while(idx < n && jewels[idx][0] <= bag){
            pq.push(jewels[idx][1]);
            idx++;
        }

        if(!pq.empty()){
            answer += pq.top();
            pq.pop();
        }
    }

    cout << answer;

    return 0;
}
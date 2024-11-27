#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, k;
    cin >> n >> k;

    vector<int> seq(k);
    vector<queue<int>> will_use(k + 1);
    vector<bool> is_using(k + 1, false);
    for(int i = 0; i < k; i++){
        cin >> seq[i];
        will_use[seq[i]].push(i);
    }

    int using_cnt = 0, answer = 0;
    for(int i = 0; i < k; i++){
        if(is_using[seq[i]]) continue;
        if(using_cnt < n){
            using_cnt++;
            is_using[seq[i]] = true;
            continue;
        }

        int product = 1, next = i;
        for(int p = 1; p <= k; p++){
            if(!is_using[p]) continue;

            while(!will_use[p].empty() && will_use[p].front() <= i) will_use[p].pop();

            if(will_use[p].empty()){
                product = p;
                next = 101;
                break;
            }

            if(next < will_use[p].front()){
                product = p;
                next = will_use[p].front();
            }
        }

        is_using[product] = false;
        is_using[seq[i]] = true;
        answer++;
    }

    cout << answer;

    return 0;
}
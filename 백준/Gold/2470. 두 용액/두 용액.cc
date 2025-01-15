#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> liquid(n);
    for(int i = 0; i < n; i++) cin >> liquid[i];

    sort(liquid.begin(), liquid.end());

    int l = 0, r = n - 1;
    pair<int, int> answer = {liquid[l], liquid[r]};

    while(l < r){
        if(abs(liquid[l] + liquid[r]) < abs(answer.first + answer.second)){
            answer = {liquid[l], liquid[r]};
        }
        
        if(liquid[l] + liquid[r] > 0) r--;
        else if(liquid[l] + liquid[r] < 0) l++;
        else break;
    }

    cout << answer.first << " " << answer.second;

    return 0;
}
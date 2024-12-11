#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> positive;
    vector<int> negative;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        
        if(num > 0) positive.push_back(num);
        else negative.push_back(num);
    }

    sort(positive.rbegin(), positive.rend());
    sort(negative.begin(), negative.end());

    int answer = 0;
    for(int i = 0; i < negative.size(); i++){
        if(i + 1 < negative.size() && negative[i] * negative[i + 1] > negative[i] + negative[i + 1]){
            answer += negative[i] * negative[i + 1];
            i++;
        }
        else answer += negative[i];
    }
    for(int i = 0; i < positive.size(); i++){
        if(i + 1 < positive.size() && positive[i] * positive[i + 1] > positive[i] + positive[i + 1]){
            answer += positive[i] * positive[i + 1];
            i++;
        }
        else answer += positive[i];
    }

    cout << answer;

    return 0;
}
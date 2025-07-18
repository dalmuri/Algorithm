#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    int answer = 0;
    vector<int> odd;
    for(int i = 0, candy; i < n; ++i){
        cin >> candy;

        if(candy & 1) odd.push_back(candy);
        else answer += candy;
    }

    if(odd.size() & 1){
        answer -= *min_element(odd.begin(), odd.end());
    }

    answer += accumulate(odd.begin(), odd.end(), 0);
    
    cout << answer;

    return 0;
}
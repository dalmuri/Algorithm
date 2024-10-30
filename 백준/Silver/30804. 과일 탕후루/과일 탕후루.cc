#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> fruits(n);
    for(int i = 0; i < n; i++) cin >> fruits[i];

    vector<int> count(10, 0);
    int answer = 0, kinds = 0, left = 0, right = 0;
    while(right < n){
        if(kinds <= 2){
            count[fruits[right]]++;
            if(count[fruits[right]] == 1) kinds++;

            right++;
        }
        else{
            count[fruits[left]]--;
            if(count[fruits[left]] == 0) kinds--;

            left++;
        }

        if(kinds <= 2 && right - left > answer) answer = right - left;
    }
    while(kinds > 2){
        count[fruits[left]]--;
        if(count[fruits[left]] == 0) kinds--;
        left++;

        if(kinds <= 2 && right - left > answer) answer = right - left;
    }

    cout << answer;

    return 0;
}
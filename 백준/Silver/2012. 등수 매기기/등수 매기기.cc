#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<bool> graded(n + 1, false);
    vector<int> complaint;
    for(int i = 0; i < n; i++){
        int grade;
        cin >> grade;

        if(grade > n || graded[grade]) complaint.push_back(grade);
        else graded[grade] = true;
    }

    sort(complaint.begin(), complaint.end());
    int idx = 0;
    long long answer = 0ll;
    for(int i = 1; i <= n; i++){
        if(!graded[i]){
            answer += abs(complaint[idx] - i);
            idx++;
        }
    }

    cout << answer;

    return 0;
}
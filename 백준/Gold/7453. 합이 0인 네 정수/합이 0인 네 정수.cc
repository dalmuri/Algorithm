#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> A(n), B(n), C(n), D(n);
    for(int i = 0; i < n; i++) cin >> A[i] >> B[i] >> C[i] >> D[i];
    
    vector<int> AB;
    for(int a : A){
        for(int b : B){
            AB.push_back(a + b);
        }
    }

    sort(AB.begin(), AB.end());
    long long answer = 0;
    for(int c : C){
        for(int d : D){
            int start = lower_bound(AB.begin(), AB.end(), -c-d) - AB.begin();
            int end = upper_bound(AB.begin(), AB.end(), -c-d) - AB.begin();
            answer += end - start;
        }
    }

    cout << answer;

    return 0;
}
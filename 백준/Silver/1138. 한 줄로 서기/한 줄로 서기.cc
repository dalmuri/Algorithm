#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> people(n + 1);
    for(int i = 1; i <= n; i++) cin >> people[i];

    vector<int> answer(n, 0);
    for(int i = 1; i <= n; i++){
        int cnt = people[i];
        for(int j = 0; j <= cnt; j++){
            if(answer[j] > 0) cnt++;
            if(j == cnt){
                answer[j] = i;
                break;
            }
        }
    }

    for(int i = 0; i < n; i++) cout << answer[i] << " ";

    return 0;
}
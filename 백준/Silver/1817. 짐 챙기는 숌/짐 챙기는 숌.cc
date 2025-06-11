#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, m;
    cin >> n >> m;

    int answer = 0;
    for(int i = 0, weight = 0, box; i < n; ++i){
        cin >> box;

        if(weight >= box) weight -= box;
        else{
            answer++;
            weight = m - box;
        }
    }

    cout << answer;

    return 0;
}
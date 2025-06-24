#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int get_honey(int bee1, int bee2, int hive, vector<int>& honey){
    int result = 0;
    result += bee1 > hive ? honey[bee1] - honey[hive - 1] : honey[hive] - honey[bee1 - 1];
    result += bee2 > hive ? honey[bee2] - honey[hive - 1] : honey[hive] - honey[bee2 - 1];
    result -= honey[bee1] - honey[bee1 - 1] + honey[bee2] - honey[bee2 - 1];

    if(min(bee2, hive) < bee1 && bee1 < max(bee2, hive)) result -= honey[bee1] - honey[bee1 - 1];
    else if(min(bee1, hive) < bee2 && bee2 < max(bee1, hive)) result -= honey[bee2] - honey[bee2 - 1];

    return result;
}

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> honey(n + 1, 0);
    for(int i = 1; i <= n; ++i){
        cin >> honey[i];
        honey[i] += honey[i - 1];
    }

    int answer = 0;
    for(int i = 2; i < n; ++i){
        answer = max(answer, get_honey(i, n, 1, honey));
        answer = max(answer, get_honey(1, n, i, honey));
        answer = max(answer, get_honey(1, i, n, honey));
    }

    cout << answer;

    return 0;
}
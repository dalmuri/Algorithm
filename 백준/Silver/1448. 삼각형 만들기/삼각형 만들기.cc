#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> lengths(n);
    for(int i = 0; i < n; i++) cin >> lengths[i];

    sort(lengths.rbegin(), lengths.rend());

    int answer = -1;
    for(int i = 0; i + 2 < n; i++){
        if(lengths[i] < lengths[i + 1] + lengths[i + 2]){
            answer = lengths[i] + lengths[i + 1] + lengths[i + 2];
            break;
        }
    }

    cout << answer;

    return 0;
}
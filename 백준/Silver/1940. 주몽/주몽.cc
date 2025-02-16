#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, m;
    cin >> n >> m;

    vector<int> materials(n);
    for(int i = 0; i < n; i++) cin >> materials[i];

    sort(materials.begin(), materials.end());

    int l = 0, r = materials.size() - 1;
    int answer = 0;
    while(l < r){
        int sum = materials[l] + materials[r];
        if(sum == m) answer++;
        
        if(sum > m) r--;
        else l++;
    }

    cout << answer;

    return 0;
}
#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<pair<int, int>> lines(n);
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        lines[i] = {x, y};
    }

    sort(lines.begin(), lines.end());

    int left = lines[0].first;
    int right = lines[0].second;
    int answer = 0;
    for(int i = 1; i < n; i++){
        if(lines[i].first <= right){
            right = max(right, lines[i].second);
        }
        else{
            answer += right - left;
            left = lines[i].first;
            right = lines[i].second;
        }
    }
    answer += right - left;

    cout << answer;

    return 0;
}
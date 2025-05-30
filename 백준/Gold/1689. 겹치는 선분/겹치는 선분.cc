#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<pair<int, int>> points(n * 2);
    for(int i = 0; i < points.size(); i+=2){
        cin >> points[i].first >> points[i + 1].first;
        points[i].second = 1;
    }

    sort(points.begin(), points.end());

    int count = 0, answer = 0;
    for(int i = 0; i < points.size(); ++i){
        if(points[i].second) answer = max(answer, ++count);
        else count--;
    }

    cout << answer;

    return 0;
}
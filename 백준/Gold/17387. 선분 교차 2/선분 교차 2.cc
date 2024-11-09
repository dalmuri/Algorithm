#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int ccw(pair<int, int> p1, pair<int, int> p2, pair<int, int> point){
    long long s = (long long)(p2.first - p1.first) * (point.second - p2.second) - (long long)(p2.second - p1.second) * (point.first - p2.first);
    if(s > 0) return 1;
    if(s < 0) return -1;
    return 0;
}

int main(){
    FASTIO

    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    pair<int, int> p1 = {x1, y1};
    pair<int, int> p2 = {x2, y2};
    pair<int, int> p3 = {x3, y3};
    pair<int, int> p4 = {x4, y4};

    int chk1 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
    int chk2 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

    int answer = 0;
    if(chk1 == 0 && chk2 == 0){ // 일직선 상에 존재
        if(min(p3, p4) <= max(p1, p2) && min(p1, p2) <= max(p3, p4)) answer = 1;
    }
    else if(chk1 <= 0 && chk2 <= 0) answer = 1;

    cout << answer;

    return 0;
}
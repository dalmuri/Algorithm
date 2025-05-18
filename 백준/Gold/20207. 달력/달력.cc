#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

bool try_insert(pair<int, int> schedule, vector<bool>& dates){
    for(int i = schedule.first; i <= schedule.second; ++i){
        if(dates[i]) return false;
    }

    for(int i = schedule.first; i <= schedule.second; ++i) dates[i] = true;

    return true;
}

int get_end_period(int start, vector<bool>& dates){
    for(int i = start + 1; i <= 365; ++i){
        if(!dates[i]) return i - 1;
    }

    return 365;
}

int get_size(int left, int right, int up, int down, int& idx, vector<vector<bool>>& calendar){
    for(int i = 0; i <= down; ++i){
        if(calendar[i][right + 1]){
            right = get_end_period(right + 1, calendar[i]);
            i = -1;
        }
    }

    if(down <= calendar.size()){
        for(int j = left; j <= right; ++j){
            if(calendar[down + 1][j]){
                return get_size(left, get_end_period(right, calendar[down + 1]), up, down + 1, idx, calendar);
            }
        }
    }

    idx = right;

    return (right - left + 1) * (down - up + 1);
}

int main(){
    FASTIO

    vector<vector<bool>> calendar(1001, vector<bool>(367, false));

    int n;
    cin >> n;
    vector<pair<int, int>> schedules(n);
    for(int i = 0; i < n; ++i) cin >> schedules[i].first >> schedules[i].second;

    sort(schedules.begin(), schedules.end(), [](pair<int, int> a, pair<int, int> b){
        if(a.first != b.first) return a.first < b.first;
        return a.second - a.first > b.second - b.first;
    });

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < calendar.size(); ++j){
            if(try_insert(schedules[i], calendar[j])){
                break;
            }
        }
    }

    int answer = 0;
    for(int i = 0; i <= 365; ++i){
        if(calendar[0][i]) answer += get_size(i, get_end_period(i, calendar[0]), 0, 0, i, calendar);
    }

    cout << answer;

    return 0;
}
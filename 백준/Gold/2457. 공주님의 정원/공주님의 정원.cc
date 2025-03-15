#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

const int calendar[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int date_to_int(int mon, int day){
    int result = 0;
    for(int i = 0; i < mon - 1; i++) result += calendar[i];
    result += day;

    return result;
}

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<pair<int, int>> flowers(n);
    for(int i = 0; i < n; i++){
        int mon1, day1, mon2, day2;
        cin >> mon1 >> day1 >> mon2 >> day2;

        flowers[i] = {date_to_int(mon1, day1), date_to_int(mon2, day2)};
    }

    sort(flowers.begin(), flowers.end());

    const int final_date = date_to_int(11, 30);
    int prev_end = date_to_int(3, 1);
    int end = 0;
    int answer = 0;
    for(int i = 0; i < n; i++){
        if(prev_end < flowers[i].first){
            if(prev_end < end){
                answer++;
                prev_end = end;

                if(end > final_date) break;
            }
            else{
                answer = 0;
                break;
            }
        }

        if(flowers[i].first <= prev_end){
            end = max(end, flowers[i].second);
        }
        else if(prev_end < end){
            answer++;
            prev_end = end;

            end = max(end, flowers[i].second);
        }
        else{
            answer = 0;
            break;
        }

        if(end > final_date) break;
    }
    if(prev_end < end) answer++;
    else answer = 0;

    if(end <= final_date) answer = 0;

    cout << answer;

    return 0;
}
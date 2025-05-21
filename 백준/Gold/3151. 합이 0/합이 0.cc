#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> students(n);
    for(int i = 0; i < n; ++i) cin >> students[i];

    sort(students.begin(), students.end());

    long long answer = 0ll;
    for(int i = 0; i + 2 < n; ++i){
        for(int j = i + 1; j + 1 < n; ++j){
            int to_find = -students[i] - students[j];
            auto iter = lower_bound(students.begin() + j + 1, students.end(), to_find);
            if(*iter == to_find){
                answer += upper_bound(students.begin() + j + 1, students.end(), to_find) - iter;
            }
        }
    }

    cout << answer;

    return 0;
}
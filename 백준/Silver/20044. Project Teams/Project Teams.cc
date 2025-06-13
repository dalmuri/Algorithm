#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> students(n * 2);
    for(int i = 0; i < n * 2; ++i) cin >> students[i];

    sort(students.begin(), students.end());

    int answer = 200'000;
    for(int i = 0; i < n; ++i) answer = min(answer, students[i] + students[n * 2 - i - 1]);

    cout << answer;

    return 0;
}
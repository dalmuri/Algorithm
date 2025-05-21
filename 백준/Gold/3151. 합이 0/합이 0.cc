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
        int left = i + 1, right = n - 1;
        while(left < right){
            int sum = students[i] + students[left] + students[right];
            if(sum < 0) left++;
            else if(sum > 0) right--;
            else{
                if(students[left] == students[right]){
                    answer += (right - left + 1) * (right - left) / 2; // nC2 = n * (n - 1) / 2
                    break;
                }

                int next_left = upper_bound(students.begin() + left + 1, students.begin() + right, students[left]) - students.begin();
                int left_cnt = next_left - left;

                int next_right = lower_bound(students.begin() + left + 1, students.begin() + right, students[right]) - students.begin() - 1;
                int right_cnt = right - next_right;

                answer += left_cnt * right_cnt;
                left = next_left;
                right = next_right;
            }
        }
    }

    cout << answer;

    return 0;
}
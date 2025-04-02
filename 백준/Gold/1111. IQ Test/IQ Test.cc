#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n;

string answer(vector<int>& nums){
    set<int> answers;
    for(int a = -200; a <= 200; ++a){
        for(int b = -20000; b <= 20000; ++b){
            bool success = true;

            for(int i = 1; i < n; ++i){
                if(nums[i - 1] * a + b != nums[i]){
                    success = false;
                    break;
                }
            }

            if(success){
                answers.insert(nums.back() * a + b);

                if(answers.size() >= 2) return "A";
            }
        }
    }

    if(answers.size() == 1) return to_string(*answers.begin());
    return "B";
}

int main(){
    FASTIO

    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; ++i) cin >> nums[i];

    cout << answer(nums);

    return 0;
}
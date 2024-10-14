#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

vector<int> get_arr(string nums){
    vector<int> result;
    if(nums.size() <= 2) return result;

    int num = 0;
    for(char c : nums){
        if('0' <= c && c <= '9') num = num * 10 + (c - '0');
        else if(c == ',' || c == ']'){
            result.push_back(num);
            num = 0;
        }
    }

    return result;
}

int main(){
    FASTIO

    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        string p, nums;
        int n;
        cin >> p >> n >> nums;

        bool reverse = false;
        bool error = false;

        int left = 0;
        int right = n - 1;

        for(char cmd : p){
            if(cmd == 'R') reverse = !reverse;
            else{
                if(right - left + 1 <= 0){
                    error = true;
                    break;
                }

                if(reverse) right--;
                else left++;
            }
        }

        if(error){
            cout << "error\n";
            continue;
        }

        vector<int> arr = get_arr(nums);
        cout << "[";
        if(reverse){
            for(int i = right; i >= left; i--){
                cout << arr[i];
                if(i > left) cout << ",";
            }
        }
        else{
            for(int i = left; i <= right; i++){
                cout << arr[i];
                if(i < right) cout << ",";
            }
        }
        cout << "]\n";
    }

    return 0;
}
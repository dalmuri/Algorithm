#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

string dictionary[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

string to_eng(int number){
    string num = to_string(number);
    string result = "";

    for(int i = 0; i < num.size(); ++i){
        result += dictionary[num[i] - '0'] + " ";
    }

    result.pop_back();
    return result;
}

int main(){
    FASTIO

    int m, n;
    cin >> m >> n;

    vector<pair<string, int>> nums(n - m + 1);
    for(int i = m; i <= n; ++i){
        nums[i - m] = {to_eng(i), i};
    }

    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size(); i+=10){
        for(int j = i; j < min(i + 10, (int)nums.size()); ++j){
            cout << nums[j].second << " ";
        }
        cout << "\n";
    }

    return 0;
}
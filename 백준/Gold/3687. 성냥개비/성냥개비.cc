#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

bool compare(const string& num1, const string& num2){
    if(num1 == "" || num1[0] == '0') return false;
    if(num2 == "" || num2[0] == '0') return true;
    if(num1.size() != num2.size()) return num1.size() < num2.size();
    return num1 < num2;
}

int main(){
    FASTIO

    string small_num[] = {"", "", "1", "7", "4", "2", "0", "8"};
    vector<string> small_dp(101, "");
    small_dp[2] = "1";
    small_dp[3] = "7";
    small_dp[4] = "4";
    small_dp[5] = "2";
    small_dp[6] = "6";
    small_dp[7] = "8";
    for(int i = 8; i < small_dp.size(); ++i){
        for(int j = 2; j < 8; ++j){
            if(i - j < 2) break;
            small_dp[i] = min(small_dp[i], small_dp[i - j] + small_num[j], compare);
            small_dp[i] = min(small_dp[i], small_num[j] + small_dp[i - j], compare);
        }
    }

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        cout << small_dp[n] << " ";

        if(n & 1){
            cout << 7;
            n -= 3;
        }
        cout << string(n / 2, '1') << "\n";
    }

    return 0;
}
#include <iostream>
#include <string>
#include <vector>

#define FASTIO; ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    FASTIO;
    
    int n;
    cin >> n;
    
    vector<int> price(n, 0);
    for(int i = 0; i < n; i++) cin >> price[i];
    
    int m;
    cin >> m;
    
    vector<string> dp(m + 1, "");
    
    for(int i = n - 1; i >= 0; i--){
        int p = price[i];
        for(int j = p; j <= m; j++){
            string new_num = dp[j - p] + to_string(i);
            if(new_num[0] == '0') new_num = to_string(i);
            
            if(dp[j].size() < new_num.size()) dp[j] = new_num;
            else if(dp[j].size() == new_num.size()) dp[j] = max(dp[j], new_num);
        }
    }
    
    cout << dp[m] << "\n";

    return 0;
}

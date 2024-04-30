#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<vector<int>> nCr(11, vector<int>(11, 1));
    for(int n = 2; n <= 10; n++){
        for(int r = 1; r < n; r++){
            nCr[n][r] = nCr[n - 1][r - 1] + nCr[n - 1][r];
        }
    }
    
    int n;
    cin >> n;
    
    vector<int> digits = {0};
    int d = 0;
    for(int i = 1; i <= 10; i++){
        digits.push_back(digits[i - 1] + nCr[10][i]);
        if(n <= digits[i]){
            d = i;
            break;
        }
    }
    
    if(n > digits.back()) cout << -1 << endl;
    else{
        vector<char> nums = {'9', '8', '7', '6', '5', '4', '3', '2', '1', '0'};
        vector<int> cmb(10, 0);
        for(int i = 0; i < d; i++) cmb[9 - i] = 1;
        
        int cnt = digits[d - 1];
        do{
            cnt++;
            if(cnt == n) break;
        }while(next_permutation(cmb.begin(), cmb.end()));

        string answer = "";
        for(int i = 0; i < 10; i++){
            if(cmb[i] == 1) answer += nums[i];
        }
        
        cout << answer << endl;
    }

    return 0;
}
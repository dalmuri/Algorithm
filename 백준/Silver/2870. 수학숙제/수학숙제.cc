#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

vector<string> nums;

void check(string& str){
    bool flag = false;
    string num = "";
    for(int i = 0; i < str.size(); i++){
        if(flag){
            if('0' <= str[i] && str[i] <= '9'){
                num.push_back(str[i]);
            }
            else{
                nums.push_back(num);
                num.clear();
                flag = false;
            }
        }
        else{
            if('0' < str[i] && str[i] <= '9'){
                flag = true;
                num.push_back(str[i]);
            }
            else if(str[i] == '0' && (i + 1 == str.size() || str[i + 1] < '0' || '9' < str[i + 1])){
                nums.push_back("0");
            }
        }
    }

    if(flag) nums.push_back(num);
}

int main(){
    FASTIO

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        
        check(str);
    }

    sort(nums.begin(), nums.end(), [](string a, string b){
        if(a.size() != b.size()) return a.size() < b.size();
        return a < b;
    });

    for(int i = 0; i < nums.size(); i++) cout << nums[i] << "\n";

    return 0;
}
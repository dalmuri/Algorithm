#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

class bigint{
    string num;

public:
    bigint(string n = "", bool is_reverse = false):num(n){
        if(!is_reverse) reverse(num.begin(), num.end());
    }

    string get(){
        string res = num;
        reverse(res.begin(), res.end());
        return res;
    }
    
    bigint operator+(const bigint& other){
        string res = "";
        bool carry = 0;
        for(int i = 0, j = 0; i < num.size() || j < other.num.size(); i++, j++){
            int digit = 0;
            if(i < num.size()) digit += num[i] - '0';
            if(j < other.num.size()) digit += other.num[i] - '0';
            digit += carry;

            if(digit >= 10){
                digit -= 10;
                carry = 1;
            }
            else carry = 0;

            res += to_string(digit);
        }
        if(carry) res += "1";

        return bigint(res, true);
    }
};

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<bigint> f(n + 1);
    f[0] = bigint("0");
    if(n > 0) f[1] = bigint("1");

    for(int i = 2; i <= n; i++) f[i] = f[i - 1] + f[i - 2];

    cout << f[n].get();

    return 0;
}
#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

class bigint{
    vector<int> num;

public:
    bigint(string number = "", bool is_reverse = false){
        if(number.empty()){
            num = {0};
            return;
        }

        num.resize(number.size());
        for(int i = 0; i < number.size(); i++){
            num[i] = number[(is_reverse ? i : number.size() - 1 - i)] - '0';
        }
    }

    bigint(int number) : bigint(to_string(number)){}

    void show(){
        for(int i = num.size() - 1; i >= 0; i--) cout << num[i];
    }

    bigint operator+(const bigint& other){
        bigint res;
        res.num.resize(max(num.size(), other.num.size()), 0);
        int carry = 0;
        for(int i = 0, j = 0; i < num.size() || j < other.num.size(); i++, j++){
            if(i < num.size()) res.num[i] += num[i];
            if(j < other.num.size()) res.num[i] += other.num[i];
            res.num[i] += carry;

            if(res.num[i] >= 10){
                res.num[i] -= 10;
                carry = 1;
            }
            else carry = 0;
        }
        if(carry) res.num.push_back(1);

        return res;
    }
};

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<bigint> f(n + 1);
    f[0] = bigint(0);
    if(n > 0) f[1] = bigint(1);

    for(int i = 2; i <= n; i++) f[i] = f[i - 1] + f[i - 2];

    f[n].show();

    return 0;
}
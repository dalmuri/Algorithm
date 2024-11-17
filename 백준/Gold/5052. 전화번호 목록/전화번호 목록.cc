#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

struct num{
    bool is_end = false;
    vector<num*> next_num;

    num(){
        next_num = vector<num*>(10);
    }

    bool update(int idx, string& numbers){
        int next = numbers[idx] - '0';
        if(next_num[next] == NULL) next_num[next] = new num();
        
        if((*next_num[next]).is_end) return false;

        if(idx + 1 == numbers.size()){
            (*next_num[next]).is_end = true;
            return true;
        }

        return (*next_num[next]).update(idx + 1, numbers);
    }
};

int main(){
    FASTIO

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        num root;

        vector<string> phone_numbers(n);
        for(int i = 0; i < n; i++){
            cin >> phone_numbers[i];
        }

        sort(phone_numbers.begin(), phone_numbers.end());

        bool flag = true;
        for(int i = 0; i < n; i++){
            if(flag && !root.update(0, phone_numbers[i])){
                flag = false;
                break;
            }
        }

        cout << (flag ? "YES\n" : "NO\n");
    }

    return 0;
}
#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

struct num{
    int is_end = 0; // 0 : 초기 상태, 1 : 마지막 번호, -1: 다음 번호 존재
    vector<num*> next_num;

    num(){
        next_num = vector<num*>(10);
    }

    bool update(int idx, string& numbers){
        int next = numbers[idx] - '0';
        if(next_num[next] == NULL) next_num[next] = new num();
        
        if((*next_num[next]).is_end == 1) return false;

        if(idx + 1 == numbers.size()){
            if((*next_num[next]).is_end == -1) return false;
            
            (*next_num[next]).is_end = 1;
            return true;
        }

        (*next_num[next]).is_end = -1;
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

        bool flag = true;
        for(int i = 0; i < n; i++){
            string numbers;
            cin >> numbers;

            if(flag && !root.update(0, numbers)) flag = false;
        }

        cout << (flag ? "YES\n" : "NO\n");
    }

    return 0;
}
#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int l, c;

bool can_cut(int len, set<int>& cut_pos, int& first_pos){
    int last_cut_pos = l, prev_pos = l, cnt = 0;
    for(auto iter = cut_pos.rbegin(); iter != cut_pos.rend(); prev_pos = *iter, ++iter){
        if(last_cut_pos - *iter > len){
            if(last_cut_pos == prev_pos) return false;
            if(last_cut_pos - prev_pos > len) return false;
            last_cut_pos = prev_pos;
            if(++cnt > c) return false;
        }
    }
    if(last_cut_pos > len){
        if(last_cut_pos == prev_pos) return false;
        if(last_cut_pos - prev_pos > len) return false;
        if(prev_pos > len) return false;
        last_cut_pos = prev_pos;
        if(++cnt > c) return false;
    }
    
    if(cnt < c) first_pos = *cut_pos.begin();
    else first_pos = last_cut_pos;
    return true;
}

int main(){
    FASTIO

    int k;
    cin >> l >> k >> c;

    set<int> cut_pos;
    for(int i = 0, pos; i < k; ++i){
        cin >> pos;
        cut_pos.insert(pos);
    }

    int left = 0, right = l, max_len = right, first_pos = 0, temp;
    while(left <= right){
        int mid = (left + right) / 2;

        if(can_cut(mid, cut_pos, temp)){
            max_len = mid;
            first_pos = temp;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }

    cout << max_len << " " << first_pos;

    return 0;
}
#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int l, k, c;

int can_cut(int len, vector<int>& cut_pos){
    int last_cut = l, cnt = 0;
    for(int i = k - 1; i >= 0; --i){
        if(last_cut - cut_pos[i] > len){
            if(cut_pos[i + 1] - cut_pos[i] > len) return 0;
            if(++cnt > c) return 0;
            last_cut = cut_pos[i + 1];
        }
    }
    if(last_cut > len){
        if(last_cut - cut_pos[0] > len) return 0;
        if(cut_pos[0] > len) return 0;
        if(++cnt > c) return 0;
        last_cut = cut_pos[0];
    }

    if(cnt < c) return cut_pos[0];
    else return last_cut;
}

int main(){
    FASTIO

    cin >> l >> k >> c;

    vector<int> cut_pos(k + 1, l);
    for(int i = 0, pos; i < k; ++i) cin >> cut_pos[i];

    sort(cut_pos.begin(), cut_pos.end());

    int left = 0, right = l, max_len = right, first_pos = 0;
    while(left <= right){
        int mid = (left + right) / 2;

        int result = can_cut(mid, cut_pos);
        if(result){
            max_len = mid;
            first_pos = result;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }

    cout << max_len << " " << first_pos;

    return 0;
}
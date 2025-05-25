#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, m;
bool can_divide(int max_sum, vector<int>& marbles){
    int cnt = 1;
    for(int i = 0, sum = 0; i < marbles.size(); ++i){
        if(marbles[i] > max_sum) return false;

        if(sum + marbles[i] <= max_sum){
            sum += marbles[i];
        }
        else{
            sum = marbles[i];
            cnt++;
        }
    }

    if(cnt > m) return false;
    return true;
}

void print_divide(int max_sum, vector<int>& marbles){
    vector<int> result;
    int cnt = 0;
    for(int i = 0, sum = 0; i < marbles.size(); ++i){
        if(sum + marbles[i] <= max_sum){
            sum += marbles[i];
            cnt++;
        }
        else{
            result.push_back(cnt);
            sum = marbles[i];
            cnt = 1;
        }
    }
    result.push_back(cnt);

    for(int i = result.size() - 1; i >= 0 && result.size() < m; --i){
        if(result[i] <= 1) continue;

        int extra = min(result[i] - 1, m - (int)result.size());
        result[i] -= extra;
        while(extra--) result.push_back(1);
    }

    for(int i = 0; i < result.size(); ++i) cout << result[i] << " ";
}

int main(){
    FASTIO

    cin >> n >> m;

    vector<int> marbles(n);
    for(int i = 0; i < n; ++i) cin >> marbles[i];

    int l = 0, r = accumulate(marbles.begin(), marbles.end(), 0), answer_sum = r;
    while(l <= r){
        int mid = (l + r) / 2;

        if(can_divide(mid, marbles)){
            r = mid - 1;
            answer_sum = mid;
        }
        else{
            l = mid + 1;
        }
    }

    cout << answer_sum << "\n";
    print_divide(answer_sum, marbles);

    return 0;
}
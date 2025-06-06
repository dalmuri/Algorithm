#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    vector<long long> count(10, 0ll);
    vector<bool> is_first(10, false);

    int n;
    cin >> n;

    for(int i = 0; i < n; ++i){
        string number;
        cin >> number;

        long long digit = 1ll;
        for(int j = number.size() - 1; j >= 0; --j, digit *= 10ll){
            count[number[j] - 'A'] += digit;
        }

        is_first[number[0] - 'A'] = true;
    }

    long long min_cnt = 10'000'000'000'000;
    int min_idx = -1;
    for(int i = 0; i < count.size(); ++i){
        if(is_first[i]) continue;

        if(count[i] < min_cnt){
            min_cnt = count[i];
            min_idx = i;
        }
    }

    count[min_idx] = 0;
    sort(count.rbegin(), count.rend());
    for(int i = 0; i < 10; ++i) count[i] *= 9 - i;

    cout << accumulate(count.begin(), count.end(), 0ll);

    return 0;
}
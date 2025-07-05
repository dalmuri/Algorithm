#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int n, k, cnt = 0;

void merge(int start, int end, vector<int>& chickens){
    int mid = (start + end + 1) / 2;
    int len = mid - start;

    vector<int> a(chickens.begin() + start, chickens.begin() + mid);
    vector<int> b(chickens.begin() + mid, chickens.begin() + end + 1);

    int i = 0, j = 0, idx = start;
    for(; i < len && j < len; ++idx){
        if(a[i] < b[j]) chickens[idx] = a[i++];
        else chickens[idx] = b[j++];
    }
    while(i < len) chickens[idx++] = a[i++];
    while(j < len) chickens[idx++] = b[j++];;

    cnt++;
}

int main(){
    FASTIO

    cin >> n;

    vector<int> chickens(n);
    for(int i = 0; i < n; ++i) cin >> chickens[i];

    cin >> k;

    queue<pair<int, int>> q;
    for(int i = 0; i < n; i+=2){
        q.push({i, i + 1});
    }

    int stage = n >> 1;
    while(q.size() >= 2 && k <= stage){
        auto [start1, end1] = q.front();
        q.pop();
        auto [start2, end2] = q.front();
        q.pop();

        merge(start1, end1, chickens);
        merge(start2, end2, chickens);
        q.push({start1, end2});

        if(cnt >= stage){
            stage >>= 1;
            cnt = 0;
        }
    }

    for(int i = 0; i < n; ++i) cout << chickens[i] << " ";

    return 0;
}
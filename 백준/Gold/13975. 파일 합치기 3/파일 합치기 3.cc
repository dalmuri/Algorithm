#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int t;
    cin >> t;
    while(t--){
        int k;
        cin >> k;

        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(int i = 0; i < k; i++){
            int file;
            cin >> file;

            pq.push(file);
        }

        long long answer = 0ll;
        while(pq.size() >= 2){
            long long file1 = pq.top();
            pq.pop();
            long long file2 = pq.top();
            pq.pop();

            answer += file1 + file2;
            pq.push(file1 + file2);
        }

        cout << answer << "\n";
    }

    return 0;
}
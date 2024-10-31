#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

struct cmp{
    bool operator()(vector<int> a, vector<int> b){
        if(a[0] != b[0]) return a[0] > b[0];
        return a[1] > b[1];
    }
};

int main(){
    FASTIO

    int n;
    cin >> n;

    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;

    for(int i = 0; i < n; i++){
        int num;
        cin >> num;

        if(num != 0) pq.push({abs(num), num});
        else{
            if(pq.empty()) cout << "0\n";
            else{
                cout << pq.top()[1] << "\n";
                pq.pop();
            }
        }
    }

    return 0;
}
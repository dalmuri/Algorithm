#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    vector<int> f(45, 0);
    f[1] = 1;
    for(int i = 2; i < f.size(); ++i) f[i] = f[i - 1] + f[i - 2];
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<int> answer;
        for(int i = f.size() - 1; i >= 1; --i){
            if(f[i] <= n){
                answer.push_back(f[i]);
                n -= f[i];
            }
        }

        for(int i = answer.size() - 1; i >= 0; --i) cout << answer[i] << " ";
        cout << "\n";
    }

    return 0;
}
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> ports(n);
    for(int i = 0; i < n; i++) cin >> ports[i];

    vector<int> lis = {ports[0]}; // longest increasing subsequence

    for(int i = 1; i < n; i++){
        if(lis.back() < ports[i]) lis.push_back(ports[i]);
        else{
            auto iter = lower_bound(lis.begin(), lis.end(), ports[i]);
            *iter = ports[i];
        }
    }

    cout << lis.size();

    return 0;
}
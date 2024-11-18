#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

vector<int> children[100'000];
int numbers[100'000];

long long calc(int node){
    long long res = numbers[node];

    for(int child : children[node]){
        res += calc(child);
    }

    if(node == 0) return res;
    return max(0ll, res);
}

int main(){
    FASTIO

    int n;
    cin >> n;

    for(int i = 0; i < n - 1; i++){
        int p, c;
        cin >> p >> c;
        children[p].push_back(c);
    }
    for(int i = 0; i < n; i++){
        cin >> numbers[i];
    }

    cout << (calc(0));

    return 0;
}
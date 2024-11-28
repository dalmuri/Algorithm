#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<long long> fib(n + 1);
    fib[1] = 1;
    for(int i = 2; i <= n; i++) fib[i] = fib[i - 1] + fib[i - 2];

    vector<long long> dist(n + 1);
    dist[1] = 4;
    for(int i = 2; i <= n; i++) dist[i] = dist[i - 1] + fib[i] * 2;

    cout << dist[n];

    return 0;
}
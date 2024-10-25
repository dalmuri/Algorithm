#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> primes;
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for(int now = 2; now <= n; now++){
        if(!is_prime[now]) continue;

        primes.push_back(now);
        if((long long)now * now > INT_MAX) continue;

        for(int i = now * now; i <= n; i += now){
            is_prime[i] = false;
        }
    }

    int left = 0, right = 0, sum = 0, answer = 0;
    while(right < primes.size()){
        if(sum < n){
            sum += primes[right++];
        }
        else if(n < sum){
            sum -= primes[left++];
        }
        else{
            answer++;
            sum -= primes[left++];
        }
    }
    while(left < primes.size() && n <= sum){
        if(sum == n) answer++;
        sum -= primes[left++];
    }

    cout << answer;

    return 0;
}
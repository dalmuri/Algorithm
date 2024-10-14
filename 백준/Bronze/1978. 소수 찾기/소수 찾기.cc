#include <string>
#include <iostream>
#include <vector>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    vector<bool> is_prime(1001, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for(int i = 2; i < is_prime.size(); i++){
        if(!is_prime[i]) continue;
        for(int n = i * i; n < is_prime.size(); n += i){
            is_prime[n] = false;
        }
    }

    int n;
    cin >> n;

    int answer = 0;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;

        if(is_prime[num]) answer++;
    }

    cout << answer;

    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int main(){
    FASTIO;
    
    int n, m;
    cin >> n >> m;
    
    vector<int> cards(n, 0);
    for(int i = 0; i < n; i++) cin >> cards[i];
    
    vector<int> comb(n, 0);
    for(int i = 0; i < 3; i++) comb[n - 1 - i] = 1;
    
    int answer = 0;
    do{
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(comb[i] == 1) sum += cards[i];
        }
        if(sum <= m) answer = max(answer, sum);
    }while(next_permutation(comb.begin(), comb.end()));
    
    cout << answer << endl;
    
    return 0;
}
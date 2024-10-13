#include <string>
#include <iostream>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int num;
    int mx = 0;
    int answer = 0;
    for(int i = 1; i <= 9; i++){
        cin >> num;
        if(mx < num){
            mx = num;
            answer = i;
        }
    }

    cout << mx << "\n" << answer;

    return 0;
}
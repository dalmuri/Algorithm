#include <vector>
#include <string>
#include <iostream>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int answer = 0;
    int tmp;

    for(int i = 0; i < 5; i++){
        cin >> tmp;
        answer += tmp * tmp;
    }

    answer %= 10;
    cout << answer;

    return 0;
}
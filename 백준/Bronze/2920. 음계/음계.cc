#include <string>
#include <iostream>
#include <vector>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    vector<int> sound(8);
    for(int i = 0; i < 8; i++){
        cin >> sound[i];
    }

    string answer = "mixed";

    bool is_ascending = true;
    for(int i = 0; i < 8; i++){
        if(sound[i] != i + 1){
            is_ascending = false;
            break;
        }
    }
    if(is_ascending) answer = "ascending";

    bool is_descending = true;
    for(int i = 0; i < 8; i++){
        if(sound[i] != 8 - i){
            is_descending = false;
            break;
        }
    }
    if(is_descending) answer = "descending";

    cout << answer;

    return 0;
}
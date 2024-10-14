#include <string>
#include <iostream>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int r;
        string s;
        cin >> r >> s;

        string answer = "";
        for(char c : s){
            answer += string(r, c);
        }

        cout << answer << "\n";
    }

    return 0;
}
#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    for(int t = 1; true; ++t){
        string str;
        cin >> str;
        if(str[0] == '-') break;

        int open = 0;;
        int answer = 0;
        for(int i = 0; i < str.size(); ++i){
            if(str[i] == '{') ++open;
            else{
                if(open == 0){
                    ++answer;
                    ++open;
                }
                else{
                    --open;
                }
            }
        }
        while(open >= 2){
            ++answer;
            open -= 2;
        }

        cout << t << ". " << answer << "\n";
    }

    return 0;
}
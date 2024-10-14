#include <string>
#include <iostream>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        string quiz;
        cin >> quiz;

        int score = 0;
        int cnt = 0;

        for(char c : quiz){
            if(c == 'O') score += ++cnt;
            else cnt = 0;
        }

        cout << score << "\n";
    }

    return 0;
}
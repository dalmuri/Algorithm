#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int x;
    cin >> x;

    string people;
    cin >> people;

    int diff = 0, last = 0, answer = 0;
    for(int i = 0; i < people.size(); ++i){
        if(last < 0 && -diff < x) diff--, last = 0, answer++;
        else if(last > 0 && diff < x) diff++, last = 0, answer++;

        if(people[i] == 'M'){
            if(diff < x) diff++, answer++;
            else if(last == 0) last = 1;
            else break; 
        }
        else{
            if(-diff < x) diff--, answer++;
            else if(last == 0) last = -1;
            else break;
        }
    }

    cout << answer;

    return 0;
}
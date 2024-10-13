#include <vector>
#include <string>
#include <iostream>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int score;
    cin >> score;

    char answer = 'F';

    if(score >= 90) answer = 'A';
    else if(score >= 80) answer = 'B';
    else if(score >= 70) answer = 'C';
    else if(score >= 60) answer = 'D';

    cout << answer;

    return 0;
}
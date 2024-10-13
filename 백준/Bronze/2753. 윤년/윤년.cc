#include <vector>
#include <string>
#include <iostream>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int year;
    cin >> year;

    int answer = 0;
    if(year % 400 == 0) answer = 1;
    else if(year % 100 == 0) answer = 0;
    else if(year % 4 == 0) answer = 1;

    cout << answer;

    return 0;
}
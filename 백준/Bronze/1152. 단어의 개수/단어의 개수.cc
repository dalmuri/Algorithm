#include <string>
#include <iostream>
#include <algorithm>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    string str;
    getline(cin, str);

    int answer = count(str.begin(), str.end(), ' ') + 1;
    if(str[0] == ' ') answer -= 1;
    if(str[str.size() - 1] == ' ') answer -= 1;
    cout << answer;

    return 0;
}
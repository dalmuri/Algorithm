#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    string str;
    cin >> str;

    vector<string> arr;
    for(int i = 0; i < str.size(); i++) arr.push_back(str.substr(i));

    sort(arr.begin(), arr.end());

    for(int i = 0; i < arr.size(); i++) cout << arr[i] << "\n";

    return 0;
}
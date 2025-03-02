#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n, c;
    cin >> n >> c;

    unordered_map<int, pair<int, int>> dictionary;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;

        if(++dictionary[num].first == 1) dictionary[num].second = i;
    }

    vector<tuple<int, int, int>> arr;
    for(auto iter = dictionary.begin(); iter != dictionary.end(); iter++){
        int num = iter->first;
        int cnt = iter->second.first;
        int order = iter->second.second;

        arr.push_back({cnt, -order, num});
    }

    sort(arr.rbegin(), arr.rend());

    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < get<0>(arr[i]); j++){
            cout << get<2>(arr[i]) << " ";
        }
    }

    return 0;
}
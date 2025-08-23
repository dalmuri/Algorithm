#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<int> men_up, men_down, women_up, women_down;
    for(int i = 0, height; i < n; ++i){
        cin >> height;

        if(height > 0) men_up.push_back(height);
        else men_down.push_back(-height);
    }
    for(int i = 0, height; i < n; ++i){
        cin >> height;

        if(height > 0) women_up.push_back(height);
        else women_down.push_back(-height);
    }

    sort(men_up.begin(), men_up.end());
    sort(men_down.begin(), men_down.end());
    sort(women_up.begin(), women_up.end());
    sort(women_down.begin(), women_down.end());

    int answer = 0;
    for(int i = 0, j = 0; i < men_up.size() && j < women_down.size(); ++i, ++j){
        while(j < women_down.size() && women_down[j] <= men_up[i]) j++;
        if(j < women_down.size()) answer++;
    }
    for(int i = 0, j = 0; i < women_up.size() && j < men_down.size(); ++i, ++j){
        while(j < men_down.size() && men_down[j] <= women_up[i]) j++;
        if(j < men_down.size()) answer++;
    }

    cout << answer;

    return 0;
}
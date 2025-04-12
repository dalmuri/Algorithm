#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

bool can_hunt(int hunter, int animal_x, int animal_y, int l){
    return abs(hunter - animal_x) + animal_y <= l;
}

int main(){
    FASTIO

    int m, n, l;
    cin >> m >> n >> l;

    vector<int> hunters(m);
    for(int i = 0; i < m; ++i) cin >> hunters[i];

    sort(hunters.begin(), hunters.end());

    int answer = 0;
    for(int i = 0; i < n; ++i){
        int animal_x, animal_y;
        cin >> animal_x >> animal_y;
        auto right = upper_bound(hunters.begin(), hunters.end(), animal_x);
        
        if(right != hunters.end() && can_hunt(*right, animal_x, animal_y, l)) ++answer;
        else if(right != hunters.begin() && can_hunt(*(right - 1), animal_x, animal_y, l)) ++ answer;
    }

    cout << answer;

    return 0;
}
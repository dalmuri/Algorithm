#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;

        vector<vector<int>> people(n, vector<int>(2));
        for(int i = 0; i < n; i++) cin >> people[i][0] >> people[i][1];

        sort(people.begin(), people.end());
        int answer = n;
        int min_grade2 = people[0][1];
        for(int i = 1; i < n; i++){
            if(people[i][1] > min_grade2) answer--;
            min_grade2 = min(min_grade2, people[i][1]);
        }

        cout << answer << "\n";
    }
    

    return 0;
}
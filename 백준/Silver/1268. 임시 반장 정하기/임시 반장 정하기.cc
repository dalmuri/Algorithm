#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<vector<int>> students(n, vector<int>(5));
    vector<vector<vector<int>>> classes(5, vector<vector<int>>(10));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 5; j++){
            cin >> students[i][j];
            classes[j][students[i][j]].push_back(i);
        }
    }

    vector<set<int>> same_class(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 5; j++){
            for(int student : classes[j][students[i][j]]){
                same_class[i].insert(student);
            }
        }
    }

    vector<int> cnt(n);
    for(int i = 0; i < n; i++) cnt[i] = same_class[i].size() - 1;

    cout << max_element(cnt.begin(), cnt.end()) - cnt.begin() + 1;

    return 0;
}
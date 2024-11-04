#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int search(int idx, int& cnt, vector<bool>& team, vector<bool>& visited, vector<int>& students){ // team cycle 시작 번호 반환
    if(team[idx]) return idx;
    if(visited[idx]) return -1;

    team[idx] = true;
    visited[idx] = true;
    int cycle = search(students[idx], cnt, team, visited, students);
    if(cycle < 0) return cycle;
    
    cnt++;
    if(cycle == idx) return -1;
    else return cycle;
}

int count(int start, int n, vector<bool>& visited, vector<int>& students){
    if(visited[start]) return 0;

    vector<bool> team(n + 1, false);
    int cnt = 0;
    search(start, cnt, team, visited, students);
    return cnt;
}

int main(){
    FASTIO

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<int> students(n + 1);
        for(int i = 1; i <= n; i++) cin >> students[i];

        vector<bool> visited(n + 1, false);

        int answer = n;
        for(int i = 1; i <= n; i++){
            answer -= count(i, n, visited, students);
        }

        cout << answer << "\n";
    }

    return 0;
}
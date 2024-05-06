#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<vector<int>> meetings(n, vector<int>(2));
    for(int i = 0; i < n; i++){
        cin >> meetings[i][0] >> meetings[i][1];
    }

    sort(meetings.begin(), meetings.end(), [](vector<int> a, vector<int> b){
        if(a[1] != b[1]) return a[1] < b[1];
        return a[0] < b[0];
    });

    int answer = 0;
    int end_time = 0;
    for(vector<int> meeting : meetings){
        if(end_time <= meeting[0]){
            answer++;
            end_time = meeting[1];
        }
    }

    cout << answer << endl;
    
    return 0;
}
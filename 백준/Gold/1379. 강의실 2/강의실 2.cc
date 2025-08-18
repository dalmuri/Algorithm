#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

struct lecture{
    int start, end, num;

    bool operator<(const lecture& other) const{
        if(start != other.start) return start < other.start;
        if(end != other.end) return end < other.end;
        return num < other.num;
    }
};

int main(){
    FASTIO

    int n;
    cin >> n;

    vector<lecture> lectures(n);
    for(int i = 0; i < n; ++i) cin >> lectures[i].num >> lectures[i].start >> lectures[i].end;

    sort(lectures.begin(), lectures.end());

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // (end time, lecture number)
    vector<int> rooms(n + 1);
    int k = 1;
    for(int i = 0; i < n; ++i){
        int room;
        if(!pq.empty() && pq.top().first <= lectures[i].start){
            room = pq.top().second;
            pq.pop();
        }
        else{
            room = pq.size() + 1;
            k = max(k, room);
        }
        
        rooms[lectures[i].num] = room;
        pq.push({lectures[i].end, room});
    }

    cout << k << "\n";
    for(int i = 1; i <= n; ++i) cout << rooms[i] << "\n";

    return 0;
}
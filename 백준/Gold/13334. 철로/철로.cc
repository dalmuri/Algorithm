#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

struct cmp{
    bool operator()(vector<int> a, vector<int> b){
        return a[0] > b[0];
    }
};

int main(){
    FASTIO

    int n, d;
    cin >> n;

    vector<vector<int>> people;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        people.push_back({min(a, b), max(a, b)});
    }

    cin >> d;

    sort(people.begin(), people.end(), [](vector<int> a, vector<int> b){
        if(a[1] != b[1]) return a[1] < b[1];
        return a[0] < b[0];
    });

    int end = people[0][1];
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    int answer = 0;
    for(vector<int> person : people){
        if(end < person[1]){
            end = person[1];
            while(!pq.empty() && pq.top()[0] < end - d) pq.pop();
        }

        if(end - d <= person[0]){
            pq.push(person);
            answer = max(answer, (int)pq.size());
        }
    }

    cout << answer;

    return 0;
}
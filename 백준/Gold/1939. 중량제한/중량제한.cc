#include <string>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool can_visit(int weight, int source, int destination, int n, vector<vector<vector<int>>>& bridges){
    vector<bool> visited(n + 1, false);
    stack<int> to_visit;
    to_visit.push(source);
    while(!to_visit.empty()){
        int now = to_visit.top();
        to_visit.pop();
        visited[now] = true;
        
        for(vector<int> bridge : bridges[now]){
            int next = bridge[0];
            int limit = bridge[1];
            if(weight <= limit && !visited[next]){
                to_visit.push(next);
                
                if(next == destination) return true; // 빠른 종료
            }
        }
    }
    
    return false;
}

int main(){
    int n, m;
    cin >> n >> m;
    
    vector<vector<vector<int>>> bridges(n + 1, vector<vector<int>>());
    int max_weight = 1;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        bridges[a].push_back({b, c});
        bridges[b].push_back({a, c});
        max_weight = max(max_weight, c);
    }
    
    int source, destination;
    cin >> source >> destination;
    
    // 이진탐색
    int start = 1;
    int end = max_weight;
    int answer = 0;
    while(start <= end){
        int mid = (start + end) / 2;
        bool res = can_visit(mid, source, destination, n, bridges);
        
        if(res){ // 도착 성공
            answer = mid;
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    
    cout << answer << endl;
    
    return 0;
}
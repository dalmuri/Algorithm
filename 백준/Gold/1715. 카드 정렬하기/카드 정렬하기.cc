#include <iostream>
#include <string>
#include <vector>
#include <queue>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

struct cmp{
    bool operator()(int a, int b){
        return a > b;
    }
};

int main(){
    FASTIO;
    
    int n;
    cin >> n;
    priority_queue<int, vector<int>, cmp> pq;
    for(int i = 0; i < n; i++){
        int card;
        cin >> card;
        pq.push(card);
    }
    
    int answer = 0;
    while(pq.size() >= 2){
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        
        answer += a + b;
        pq.push(a + b);
    }
    
    cout << answer << endl;
    
    return 0;
}
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int get_time(string time){
    int hour = stoi(time.substr(0, 2));
    int minute = stoi(time.substr(3));
    
    return hour * 60 + minute;
}

int solution(vector<vector<string>> book_time) {
    // 입실 시간을 기준으로 오름차순 정렬
    sort(book_time.begin(), book_time.end(), [](vector<string> a, vector<string> b){ return a[0] < b[0]; });
    
    priority_queue<int, vector<int>, greater<int>> rooms; // min_heap
    rooms.push(get_time(book_time[0][1]));
    for(int i = 1; i < book_time.size(); i++){
        int start_time = get_time(book_time[i][0]);
        int end_time = get_time(book_time[i][1]);
        
        if(rooms.top() + 10 <= start_time) rooms.pop();
        
        rooms.push(end_time);
    }
    
    return rooms.size();
}
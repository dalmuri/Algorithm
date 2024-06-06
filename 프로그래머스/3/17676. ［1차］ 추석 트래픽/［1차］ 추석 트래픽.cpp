#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int get_time(string line){
    int h = stoi(line.substr(11, 2));
    int m = stoi(line.substr(14, 2));
    int s = stoi(line.substr(17, 2));
    int ms = stoi(line.substr(20, 3));
    
    return h * 3'600'000 + m * 60'000 + s * 1'000 + ms;
}

int get_delay(string line){
    string t = line.substr(24);
    int result = stoi(t.substr(0, 1)) * 1000;
    
    if(t.size() == 4) result += stoi(t.substr(2, 1)) * 100;
    else if(t.size() == 5) result += stoi(t.substr(2, 2)) * 10;
    else if(t.size() == 6) result += stoi(t.substr(2, 3));
    
    return result;
}

int solution(vector<string> lines) {
    vector<vector<int>> req(lines.size(), vector<int>(2, 0));
    for(int i = 0; i < lines.size(); i++){
        int end = get_time(lines[i]);
        int delay = get_delay(lines[i]);
        int start = max(0, end - delay + 1);
        
        req[i][0] = start;
        req[i][1] = end;
    }
    
    int answer = 0;
    for(int i = 0; i < req.size(); i++){
        int cnt = 1;
        for(int j = i + 1; j < req.size(); j++){
            if(req[j][0] < req[i][1] + 1000) cnt++;
        }
        
        answer = max(answer, cnt);
    }
    
    return answer;
}
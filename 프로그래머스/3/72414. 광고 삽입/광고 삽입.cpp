#include <string>
#include <vector>

using namespace std;

int str2int(string time){
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));
    int s = stoi(time.substr(6, 2));
    
    return h * 3600 + m * 60 + s;
}

string int2str(int time){
    int h = time / 3600;
    time %= 3600;
    int m = time / 60;
    time %= 60;
    int s = time;
    
    return string(2 - to_string(h).size(), '0') + to_string(h) + ":" +
           string(2 - to_string(m).size(), '0') + to_string(m) + ":" +
           string(2 - to_string(s).size(), '0') + to_string(s);
}

string solution(string play_time, string adv_time, vector<string> logs) {
    int play = str2int(play_time);
    vector<long long> prefix_sum(play + 1, 0);
    for(string log : logs){
        int start = str2int(log.substr(0, 8));
        int end = str2int(log.substr(9));
        
        prefix_sum[start]++;
        prefix_sum[end]--;
    }
    
    for(int i = 1; i <= play; i++) prefix_sum[i] += prefix_sum[i - 1]; // 초마다 시청자 수 계산
    for(int i = 1; i <= play; i++) prefix_sum[i] += prefix_sum[i - 1]; // 누적합으로 만듦
    
    int adv = str2int(adv_time);
    int max_start_time = 0;
    long long max_accm = prefix_sum[adv - 1];
    for(int i = 1; i + adv <= play; i++){
        if(max_accm < prefix_sum[i + adv - 1] - prefix_sum[i - 1]){
            max_accm = prefix_sum[i + adv - 1] - prefix_sum[i - 1];
            max_start_time = i;
        }
    }
    return int2str(max_start_time);
}
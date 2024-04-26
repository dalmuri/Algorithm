#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, int> car_in;
    map<string, int> car_time;
    for(string record : records){
        int time = stoi(record.substr(0, 2))*60 + stoi(record.substr(3, 2));
        string carnum = record.substr(6, 4);
        if(record.substr(11) == "IN") car_in[carnum] = time;
        else {
            car_time[carnum] += time - car_in[carnum];
            car_in.erase(carnum);
        }
    }
    for(pair<string, int> car : car_in){
        car_time[car.first] += 23*60+59 - car.second;
    }
    car_in.clear();
    
    for(pair<string, int> car : car_time){
        if(car.second <= fees[0]) 
            answer.push_back(fees[1]);
        else
            answer.push_back(fees[1] + ceil((double)(car.second-fees[0]) / fees[2]) * fees[3]);
    }
    return answer;
}
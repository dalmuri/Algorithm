#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void dfs(int now, vector<bool> banned, vector<vector<int>>& banned_idxs, set<vector<bool>>& cases){
    if(now >= banned_idxs.size()){
        cases.insert(banned);
        return;
    }
    
    for(int i = 0; i < banned_idxs[now].size(); i++){
        int idx = banned_idxs[now][i];
        if(banned[idx]) continue;
        
        banned[idx] = true;
        dfs(now + 1, banned, banned_idxs, cases);
        banned[idx] = false;
    }
}

bool matches_id(string ban, string usr){
    if(usr.size() != ban.size()) return false;
    
    for(int i = 0; i < ban.size(); i++){
        if(ban[i] == '*') continue;
        else if(usr[i] != ban[i]) return false;
    }
    return true;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    set<vector<bool>> cases;
    vector<vector<int>> banned_idxs;
    for(int i = 0; i < banned_id.size(); i++){
        vector<int> idxs;
        for(int j = 0; j < user_id.size(); j++){
            if(matches_id(banned_id[i], user_id[j])) idxs.push_back(j);
        }
        banned_idxs.push_back(idxs);
    }
    
    sort(banned_idxs.begin(), banned_idxs.end(), [](auto a, auto b){ return a.size() < b.size(); });
    
    dfs(0, vector<bool>(user_id.size(), false), banned_idxs, cases);
    
    return cases.size();
}
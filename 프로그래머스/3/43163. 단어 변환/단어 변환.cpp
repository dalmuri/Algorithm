#include <string>
#include <vector>

using namespace std;

bool can_covert(string a, string b){
    int cnt = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i]){
            cnt++;
            if(cnt > 1) return false;
        }
    }
    if(cnt == 0) return false;
    return true;
}

void dfs(string now, int step, vector<string>& words, vector<int>& steps){
    for(int i = 0; i < words.size(); i++){
        if(can_covert(now, words[i]) && step < steps[i]){
            steps[i] = step;
            dfs(words[i], step + 1, words, steps);
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int inf = 100;
    vector<int> steps(words.size(), inf);
    int tar = -1;
    for(int i = 0; i < words.size(); i++){
        if(words[i] == target) tar = i;
    }
    if(tar == -1) return 0;
    
    dfs(begin, 1, words, steps);
    
    return steps[tar];
}
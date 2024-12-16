#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
    FASTIO

    string s, t;
    cin >> s >> t;

    bool is_reversed = false;
    int left = 0, right = t.size() - 1;

    while(right - left + 1 > s.size()){
        if(is_reversed){
            if(t[left] == 'A') left++;
            else if(t[left] == 'B'){
                left++;
                is_reversed = false;
            }
            else break;
        }
        else{
            if(t[right] == 'A') right--;
            else if(t[right] == 'B'){
                right--;
                is_reversed = true;
            }
            else break;
        }
    }

    int answer = 1;
    if(is_reversed){
        for(int i = 0; i < s.size(); i++){
            if(s[i] != t[right - i]){
                answer = 0;
                break;
            }
        }
    }
    else{
        for(int i = 0; i < s.size(); i++){
            if(s[i] != t[left + i]){
                answer = 0;
                break;
            }
        }
    }

    cout << answer;

    return 0;
}
#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

string make_palindrome(map<char, int> cnt){
    string pre = "";
    string mid = "";
    for(auto iter = cnt.begin(); iter != cnt.end(); ++iter){
        if(iter->second & 1){
            if(mid == "") mid = iter->first;
            else return "I'm Sorry Hansoo";
        }

        pre += string(iter->second / 2, iter->first);
    }

    string post;
    reverse_copy(pre.begin(), pre.end(), back_inserter(post));

    return pre + mid + post;
}

int main(){
    FASTIO

    string name;
    cin >> name;

    map<char, int> cnt;
    for(int i = 0; i < name.size(); ++i) cnt[name[i]]++;

    cout << make_palindrome(cnt);

    return 0;
}
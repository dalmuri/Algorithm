#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int count_obj(int idx, char obj, string& mines){
    int count = 0;
    if(idx > 0 && mines[idx - 1] == obj) count++;
    if(mines[idx] == obj) count ++;
    if(idx + 1 < mines.size() && mines[idx + 1] == obj) count++;

    return count;
}

void change_to(int idx, char to, string& mines){
    if(idx > 0 && mines[idx - 1] == '#') mines[idx - 1] = to;
    if(mines[idx] == '#') mines[idx] = to;
    if(idx + 1 < mines.size() && mines[idx + 1] == '#') mines[idx + 1] = to;
}

int main(){
    FASTIO

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<string> mines(2);
        cin >> mines[0] >> mines[1];

        for(int i = 0; i < n; ++i){
            if(mines[0][i] == '0') change_to(i, 'X', mines[1]);
            else if(mines[0][i] == '3') change_to(i, '*', mines[1]);
        }

        for(int i = 0; i < n; ++i){
            if(mines[0][i] == '1'){
                if(count_obj(i, '*', mines[1]) == 1) change_to(i, 'X', mines[1]);
                else if(count_obj(i, '*', mines[1]) + count_obj(i, '#', mines[1]) == 1) change_to(i, '*', mines[1]);
                else{
                    mines[1][i] = '*';
                    change_to(i, 'X', mines[1]);
                }
            }
            else if(mines[0][i] == '2'){
                if(count_obj(i, '*', mines[1]) == 2) change_to(i, 'X', mines[1]);
                else if(count_obj(i, '*', mines[1]) + count_obj(i, '#', mines[1]) == 2) change_to(i, '*', mines[1]);
                else{
                    mines[1][i] = '*';
                    if(count_obj(1, '*', mines[1]) < 2) mines[1][i + 1] = '*';
                }
            }
        }

        int answer = 0;
        for(int i = 0; i < n; ++i) if(mines[1][i] == '*') answer++;

        cout << answer << "\n";
    }

    return 0;
}
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

        string counts, mines;
        cin >> counts >> mines;

        int answer = 0;
        for(int i = 0; i < n; ++i){
            bool flag1 = i == 0 || counts[i - 1] != '0';
            bool flag2 = counts[i] != '0';
            bool flag3 = i + 1 == n || counts[i + 1] != '0';

            if(flag1 && flag2 && flag3){
                if(i > 0) counts[i - 1] -= 1;
                counts[i] -= 1;
                if(i + 1 < n) counts[i + 1] -= 1;

                answer++;
            }
        }

        cout << answer << "\n";
    }

    return 0;
}
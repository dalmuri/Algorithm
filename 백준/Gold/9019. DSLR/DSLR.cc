#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int D(int num){
    return num * 2 % 10000;
}

int S(int num){
    return num > 0 ? num - 1 : 9999;
}

int L(int num){
    int d1 = num / 1000;
    return (num - d1 * 1000) * 10 + d1;
}

int R(int num){
    int d4 = num % 10;
    return num / 10 + d4 * 1000;
}

int main(){
    FASTIO

    int T;
    cin >> T;
    while(T--){
        int a, b;
        cin >> a >> b;

        queue<pair<int, string>> q;
        q.push({a, ""});
        vector<bool> visited(10000, false);
        visited[a] = true;
        string answer = "";
        while(!q.empty()){
            int num = q.front().first;
            string cmd = q.front().second;
            q.pop();

            if(num == b){
                answer = cmd;
                break;
            }

            if(!visited[D(num)]) {q.push({D(num), cmd + "D"}); visited[D(num)] = true;}
            if(!visited[S(num)]) {q.push({S(num), cmd + "S"}); visited[S(num)] = true;}
            if(!visited[L(num)]) {q.push({L(num), cmd + "L"}); visited[L(num)] = true;}
            if(!visited[R(num)]) {q.push({R(num), cmd + "R"}); visited[R(num)] = true;}
        }

        cout << answer << "\n";
    }

    return 0;
}
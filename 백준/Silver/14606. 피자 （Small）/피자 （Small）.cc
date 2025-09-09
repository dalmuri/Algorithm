#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

vector<int> fun;
int get_fun(int height){
    if(fun[height] >= 0) return fun[height];
    else{
        int h1 = height / 2;
        int h2 = height - h1;
        return fun[height] = h1 * h2 + get_fun(h1) + get_fun(h2);
    }
}

int main(){
    FASTIO

    int n;
    cin >> n;

    fun.resize(n + 1, -1);
    fun[1] = 0;

    cout << get_fun(n);

    return 0;
}
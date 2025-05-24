#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

vector<int> cubes(20);
int answer = 0;

bool try_fill(int len, int wid, int hei){
    if(len > wid) swap(len, wid);
    if(len > hei) swap(len, hei);
    if(wid > hei) swap(wid, hei);

    if(len <= 0) return true;

    int idx = -1;
    for(int i = 0, cube = 1; cube <= len; cube <<= 1, ++i){
        if(cubes[i] > 0) idx = i;
    }
    if(idx < 0) return false;

    cubes[idx]--;
    int size = 1 << idx;
    answer++;
    return try_fill(len, wid, hei - size) && try_fill(len, wid - size, size) && try_fill(len - size, size, size);
}

int main(){
    FASTIO

    int length, width, height, n;
    cin >> length >> width >> height >> n;

    for(int i = 0; i < n; ++i){
        int a;
        cin >> a >> cubes[a];
    }

    if(try_fill(length, width, height)) cout << answer;
    else cout << "-1";

    return 0;
}
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int cnt = 1;
    int num = 666;
    while(cnt < n){
        num++;
        
        if(to_string(num).find("666") != string::npos){
            cnt++;
        }
    }
    cout << num << endl;
    
    return 0;
}
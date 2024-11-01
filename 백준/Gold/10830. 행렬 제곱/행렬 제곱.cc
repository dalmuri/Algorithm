#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

class matrix{
public:
    int n;
    vector<vector<long long>> mat;

    matrix(int n){
        this->n = n;
        mat = vector<vector<long long>>(n, vector<long long>(n, 0ll));
    }

    matrix operator*(matrix& other){
        matrix result(n);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    result.mat[i][j] += mat[i][k] * other.mat[k][j];
                    result.mat[i][j] %= 1000;
                }
            }
        }

        return result;
    }

    void print(){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << mat[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

int main(){
    FASTIO

    int n;
    long long b;
    cin >> n >> b;

    matrix A(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> A.mat[i][j];
        }
    }

    matrix answer(n);
    for(int i = 0; i < n; i++) answer.mat[i][i] = 1;

    while(b){
        if(b & 1){
            answer = answer * A;
            b--;
        }
        else{
            A = A * A;
            b /= 2;
        }
    }

    answer.print();

    return 0;
}
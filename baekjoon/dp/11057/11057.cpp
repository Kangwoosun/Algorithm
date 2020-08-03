#include <iostream>

using namespace std;



int d[1001][10] = {{},{1,1,1,1,1,1,1,1,1,1},};

int dp(int n){
    
    for(int i = 2; i<=n; ++i){
        
        for(int j = 0; j<=9; ++j){
            d[i][0] = (d[i][0] + d[i-1][j]) % 10007;
        }
        for(int j = 1; j<=9; ++j){
            d[i][1] = (d[i][1] + d[i-1][j]) % 10007;
        }
        for(int j = 2; j<=9; ++j){
            d[i][2] = (d[i][2] + d[i-1][j]) % 10007;
        }
        for(int j = 3; j<=9; ++j){
            d[i][3] = (d[i][3] + d[i-1][j]) % 10007;
        }
        for(int j = 4; j<=9; ++j){
            d[i][4] = (d[i][4] + d[i-1][j]) % 10007;
        }
        for(int j = 5; j<=9; ++j){
            d[i][5] = (d[i][5] + d[i-1][j]) % 10007;
        }
        for(int j = 6; j<=9; ++j){
            d[i][6] = (d[i][6] + d[i-1][j]) % 10007;
        }
        for(int j = 7; j<=9; ++j){
            d[i][7] = (d[i][7] + d[i-1][j]) % 10007;
        }
        for(int j = 8; j<=9; ++j){
            d[i][8] = (d[i][8] + d[i-1][j]) % 10007;
        }
        for(int j = 9; j<=9; ++j){
            d[i][9] = (d[i][9] + d[i-1][j]) % 10007;
        }
    }
    
    return (((((((((d[n][0] + d[n][1]) % 10007 + d[n][2]) % 10007 + d[n][3])
     % 10007+ d[n][4]) % 10007 + d[n][5]) % 10007 + d[n][6]) % 10007 + d[n][7]) % 10007
     + d[n][8]) % 10007 + d[n][9]) % 10007;
}



int main(){
    int N;
    cin >> N;
    
    cout << dp(N);
    return 0;
}
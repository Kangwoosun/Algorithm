#include <iostream>
#include <vector>
using namespace std;

int d[201][201];


int dp(int N, int K){
    
    for(int i = 0; i<=N; ++i)
        d[1][i] = 1;
    
    for(int i = 0; i<=K; ++i)
        d[i][0] = 1;
    
    for(int i = 2; i<=K; ++i){
        for(int j = 1; j<=N; ++j){
            
            d[i][j] = (d[i][j-1] + d[i-1][j])%1000000000;
            
        }
    }
    
    return d[K][N];
}


int main(){
    
    int N, K;
    
    cin >> N >> K;
    cout << dp(N, K);
}
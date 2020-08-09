#include <iostream>
using namespace std;


long long  d[91][2] = {{}, {0,1}};
long long  dp(int n){
    
    for(int i = 2; i<=n; ++i){
        d[i][0] = d[i-1][0]+d[i-1][1];
        d[i][1] = d[i-1][0];
    }
    
    return d[n][0]+d[n][1];
    
}

int main(){
    int N;
    
    cin >> N;
    cout << dp(N);
}
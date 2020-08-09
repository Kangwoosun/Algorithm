#include <iostream>
using namespace std;

int d[100001][3]= {{},{1,0,0},{0,1,0},{1,1,1}};

int count = 4;

int dp(int n){
    
    for(int i = count; i<=n; ++i){
        d[i][0] = (d[i-1][1] + d[i-1][2]) % 1000000009;
        d[i][1] = (d[i-2][0] + d[i-2][2]) % 1000000009;
        d[i][2] = (d[i-3][0] + d[i-3][1]) % 1000000009;
    }
    
    
    return ((d[n][0]+d[n][1]) % 1000000009 +d[n][2]) % 1000000009;
}
    
int main(){
    
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, input;
    
    
    cin >> N;
    
    for(int i =0; i<N;++i){
        cin >> input;
        cout << dp(input) << '\n';  
        if(count < input)
            count = input;
    }
    return 0;
}
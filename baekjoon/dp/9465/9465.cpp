#include <iostream>
using namespace std;


int d[2][100000];
int s[2][100000];

int max(int a, int b){
    return (a>b ? a : b);
}

int dp(int n){
    s[0][0] = d[0][0];
    s[1][0] = d[1][0];
    s[0][1] = d[0][1] + s[1][0];
    s[1][1] = d[1][1] + s[0][0];
    


    for(int i = 2; i<n; ++i){
        s[0][i] = d[0][i] + max(s[1][i-1], s[1][i-2]);
        s[1][i] = d[1][i] + max(s[0][i-1], s[0][i-2]);
    }
    
    return max(s[0][n-1], s[1][n-1]);
}


int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N,T, input;
    cin >> T;
    
    for (int i =0; i<T; ++i){
        cin >> N;
        
        for(int k = 0; k<2; ++k){
        
            for(int j=0; j<N; ++j){
                cin >> input;
                d[k][j] = input;
                
            }
        }
        cout << dp(N) << '\n';
    }
    
    
    
}
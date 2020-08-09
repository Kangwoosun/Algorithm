#include <iostream>
#include <climits>
#include <cmath>
using namespace std;


int d[100001];

int min(int a, int b){
    return (a<b?a:b);
}

int dp(int n){
    
    for(int i =1; i<=n; ++i){
        
        d[i] = i;
        
        for(int j = 1; j*j<=i; ++j){
            d[i] = min(d[i], d[i-j*j]+1);
        }
    }
    
    
    return d[n];
}


int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N;
    
    cin >> N;
    cout << dp(N); 
}
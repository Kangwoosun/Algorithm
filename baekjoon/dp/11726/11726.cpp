#include <iostream>
using namespace std;

long long s[1001];
long long dp(int n){
    
    s[1] = 1;
    s[2] = 2;
    
    for(int i = 3; i<=n; ++i){
        s[i] = (s[i-1] + s[i-2])%10007;
    }
    
    return s[n];
    
}

int main(){
    
    int N;
    cin >> N;
    
    cout << dp(N) ;
    return 0;
}
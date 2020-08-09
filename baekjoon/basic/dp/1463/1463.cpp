#include <iostream>
using namespace std;


int v[1000000];

int min(int a, int b){
    return a<b ? a : b;
}

int dp(int n){
    v[1] = 0;
    v[2] = 1;
    v[3] = 1;
    
    for(int i =4; i<=n; ++i){
        
        v[i] = v[i-1]+1;
        if(!(i%3))
            v[i] = min(v[i],v[i/3]+1);
        if(!(i%2))
            v[i] = min(v[i],v[i/2]+1);
        
    }
    return v[n];
    
}



int main(){
    
    int N;
    
    cin >> N;
    
    cout << dp(N);
}
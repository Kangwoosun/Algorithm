#include <iostream>
using namespace std;


int card[10001];
int value[10001];

int max(int a, int b){
    return (a>b ? a : b);
}
int dp(int n){
    
    value[1] = card[1];
    for(int i =2; i<=n; ++i){
        value[i] = card[i];
        for(int j =i-1; j>=(i+1)/2; --j){
            value[i] = max(value[i], value[j] + value[i-j]);
        }
    }
    
    return value[n];
}


int main(){
    int N, input;
    
    cin >> N;
    
    for(int i=1; i<=N; ++i){
        cin >> input;
        card[i] = input;
    }
    
    cout << dp(N);
}
#include <iostream>
#include <utility>
#include <climits>
using namespace std;


int arr[100001];
int d[100001];
int s[100001];

int max(int a, int b){
    return (a>b?a:b);
}

int dp(int n){
    int result = arr[1];
    
    d[1] = s[1] = arr[1];
    
    
    for(int i = 2; i<=n; ++i){
        
        d[i] = max(d[i-1] + arr[i], arr[i]);
        s[i] = max(d[i-1], s[i-1] + arr[i]);
        result = max(result, d[i]);
        result = max(result, s[i]);
    }
    
    return result;
}


int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, input; 
    cin >> N;
    
    for(int i = 1; i<=N;++i){
        cin >> input;
        arr[i] = input;
    }
    
    cout << dp(N);
    
    return 0;
}
#include <iostream>
using namespace std;



int d[1001];
int arr[1001];

int max(int a, int b){
    return (a>b?a:b);
}

int dp(int n){
    
    int result = 0;
    d[1] = 1;
    
    for(int i = 1; i<=n; ++i){
        int min =0;
        
        for(int j =0; j<i; ++j){
            
            if(arr[i] < arr[j])
                if(min < d[j])
                    min = d[j];
            
        }
        d[i] = min + 1;
        result = max(result, d[i]);
    }
    
    return result;
    
}

int main(){
    
    int N, input;
    cin >> N;
    
    for(int i =1;i <= N; ++i){
        cin >> input;
        arr[i] = input;
    }
    
    cout << dp(N);
    
    return 0;
    
}
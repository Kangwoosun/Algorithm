#include <iostream>
using namespace std;


int d[1000001] = {0,1,2,4,};
int before = 4;
int dp(int n){
    
    for(int i = before; i<= n; ++i){
        d[i] = ((d[i-1]+ d[i-2])%1000000009 + d[i-3])%1000000009;
    }
    return d[n];
}
int main(){
    
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, input;
    cin >> N;
    for(int i =0; i<N; ++i){
        cin >> input;
        cout << dp(input) << '\n';
        if(before < input)
            before = input;
    }
}
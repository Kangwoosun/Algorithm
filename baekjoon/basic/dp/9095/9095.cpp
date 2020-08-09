#include <iostream>
using namespace std;


int d[11];

int dp(int n){
    
    for(int i = 4; i<= n; ++i){
        if(d[i] == 0){
            d[i] = d[i-1] + d[i-2] + d[i-3];
        }
    }
    return d[n];
}
int main(){
    int N, input;
    cin >> N;
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    for(int i =0; i<N; ++i){
        cin >> input;
        cout << dp(input) << '\n';
    }
}
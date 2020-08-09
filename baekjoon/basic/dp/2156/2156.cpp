#include <iostream>
#include <utility>
using namespace std;


int d[10001];
pair<int,int> s[10001];

int max(int a, int b, int c){
    
    int tmp = a;
    
    if(b > tmp)
        tmp = b;
    
    if(c > tmp)
        tmp = c;
    
    return tmp;
}
int dp(int n){
    
    for(int i = 4; i<=n+3; ++i){
        
        auto [v,c] = s[i-1];
        
        if (c == 2){
            int large = max(d[i]+d[i-1]+s[i-3].first, s[i-1].first, s[i-2].first+d[i]);
            int count = -1;
            if(large == d[i]+d[i-1]+s[i-3].first)
                count = 2;
            else if(large == s[i-1].first)
                count = 0;
            else if(s[i-2].first+d[i])
                count = 1;
            
            s[i] = make_pair(large, count);
        }
        else{
            s[i] = make_pair(v+d[i], c+1);
        }
    }
    
    return s[n+3].first;
}


int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, input;
    cin >> N;
    
    for(int i =4; i<=N+3; ++i){
        cin >> input;
        d[i] = input;
    }
    
    cout << dp(N);
}
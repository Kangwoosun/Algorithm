#include <iostream>
using namespace std;

int T[16], P[16];
bool check[16];
int N, _max = -1000;

void calc(){
    int sum = 0;
    
    for(int i= 1; i<= N; i++){
        if(check[i]){
            sum += P[i];
            
        }
    }
    
    
    if(sum > _max)
        _max = sum;
        
    return;
    
}


void DFS(int idx){
    
    if(idx > N+1){
        return;
    }
    
    
    for(int i = idx; i<= N; i++){
        
        if(check[i] == true) continue;
        
        
        check[i] = true;
        
        DFS(i+T[i]);
        
        check[i] = false;
    }
    calc();
    return;
}




int main(){
    
    
    
    cin >> N;
    
    for(int i =1; i<=N;i++){
        cin >> T[i] >> P[i];
    }
    
    DFS(1);
    
    cout << _max;
    
    return 0;
}
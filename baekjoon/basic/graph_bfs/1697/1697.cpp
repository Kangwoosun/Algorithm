#include <iostream>
#include <queue>
#include <utility>
using namespace std;


int N , K;
bool visit[100001];

bool isin(int x){
    return (0<=x && x<=100000 ? true : false);
}

int bfs(){
    
    int tmp;
    queue<pair<int,int>> q;
    q.push(make_pair(N, 0));
    visit[N] = true;
    while(!q.empty()){
        
        auto[x, c] = q.front();
        q.pop();
        
        if(x == K)
            return c;
        
        for(int i =0; i<3; ++i){
            
            switch(i){
            case 0:
                tmp = x+1;
                break;
            case 1:
                tmp = x-1;
                break;
            case 2:
                tmp = x*2;
                break;
            }
            
            if(isin(tmp) && !visit[tmp]){
                q.push(make_pair(tmp, c+1));
                visit[tmp]= true;   
            }
        }
    }
    
    
    return -1;
    
}


int main(){
    
    
    cin >> N >> K;
    
    if(K<=N)
        cout << N-K;
    else
        cout << bfs();
    
    return 0;
}
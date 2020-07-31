#include <iostream>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;


int N , K;
int visit[100001];

bool isin(int x){
    return (0<=x && x<=100000 ? true : false);
}

int bfs(){
    
    for(int i = 0; i<=100000; ++i)
        visit[i] = INT_MAX;
    
    int tmp;
    queue<int> q;
    
    q.push(N);
    
    visit[N] = 0;
    
    while(!q.empty()){
        
        int x = q.front();
        q.pop();
        
        if(x == K){
            return visit[x];
        }
        
        tmp = x+1;
        
        if(isin(tmp) && (visit[tmp] > visit[x])){
            visit[tmp] = visit[x] + 1;
            q.push(tmp);
        }
    
        tmp = x-1;
        
        if(isin(tmp) &&  (visit[tmp] > visit[x])){
            visit[tmp] = visit[x] + 1;
            q.push(tmp);
        }

        tmp = x*2;
        
        if(isin(tmp) && (visit[tmp] >= visit[x])){
            visit[tmp] = visit[x];
            q.push(tmp);
        }
    }
    
    return -1;
    
}


int main(){
    
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    
    if(K<=N)
        cout << N-K;
    else
        cout << bfs();
    
    return 0;
}

// Reference : https://yabmoons.tistory.com/96
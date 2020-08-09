#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool visit[1001];
vector<int> v[1001];
void dfs(int start){
    
    cout << start << ' ';
    
    visit[start] = true;
    
    for(int i=0; i<v[start].size(); ++i)
        if(!visit[v[start][i]])
            dfs(v[start][i]);
    
    return;
}


void bfs(int start){
    
    queue<int> q;
    
    q.push(start);
    visit[start] = true;
    while(!q.empty()){
        
        
        int index = q.front();
        q.pop();
        
        cout << index << ' ';
        
        for(int i =0; i<v[index].size(); ++i)
            if(!visit[v[index][i]]){
                q.push(v[index][i]);
                visit[v[index][i]] = true;
            }
    }
    return;
    
}



int main(){
    int N, M, V;
    
    int a, b;
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> M >> V;
    
    for(int i=0; i<M; ++i){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    for(int i = 1; i<=N; ++i){
        sort(v[i].begin(), v[i].end());
    }
    
    
    
    dfs(V);
    cout << endl;
    memset(visit, 0, sizeof(visit));
    bfs(V);
    
}
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

#define RED 1
#define BLUE 2


int v_color[20010];
vector<int> v[20010];
bool visit[20010];


int dfs(int start, int color){
    
    visit[start] = true;
    v_color[start] = color;
    
    for(auto& i : v[start]){
        
        if(!visit[i]){
            if(dfs(i, color ^ 3))
                return 1;
        }
        else{
            if(v_color[i] == color){
                return 1;
            }
        }
        
    }
    
    return 0;
}

int bfs(int start, int color){
    
    int index;
    
    visit[start] = true;
    v_color[start] = color;
    
    queue<int> q;
    q.push(start);
    
    while(!q.empty()){
        
        index = q.front();
        q.pop();
        
        for(auto&i : v[index]){
            if(visit[i]){
                if(v_color[i] == v_color[index]){
                    return 1;
                }
            }
            else{
                q.push(i);
                visit[i] = true;
                v_color[i] = v_color[index] ^ 3;
            }
        }
    }
    return 0;
}


int main(){
    
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int K, V, E;
    int a, b;
    bool isit;
    cin >> K;
    
    
    for(int i=0;i<K;++i){
        cin >> V >> E;
        isit = true;    
        for(int j=0; j<E;++j){
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        
        /* DFS
        for(int j=1; j<=V; ++j){
            
            if(!visit[j]){
                if(dfs(j,RED)){
                    isit = false;
                    break;
                }
            }
            
        }
        
        */
        
        // BFS
        for(int j =1; j<= V; ++ j){
            if(!visit[j]){
                if(bfs(j,RED)){
                    isit = false;
                    break;
                }
                
            }
        }
        
        if(isit)
            cout << "YES";
        else
            cout << "NO";
        
        for(int j=1; j<=V; ++j)
            v[j].clear();
        
        if(i != K-1){
            cout << '\n';
            memset(visit, 0, sizeof(visit));
            memset(v_color, 0, sizeof(v_color));
        }
    }
    return 0;
    
}
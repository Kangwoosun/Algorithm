#include <iostream>
#include <queue>
#include <utility>
#include <climits>
using namespace std;

int N, M;
bool v[1001][1001];
pair<int,bool> visit[1001][1001];

bool isin(int x, int y){
    return (1<=x && x<=N && 1<= y && y<=M);
}

int mx[] = {0,0,-1,1};
int my[] = {1,-1,0,0};
struct node{
    int x;
    int y;
    bool b;
};

int bfs(){
    
    queue<node> q;
    q.push({1,1,false});
    
    
    for(int i=1; i<=N; ++i)
        for(int j=1; j<=M; ++j){
            visit[i][j] = make_pair(INT_MAX, false);
        }
    visit[1][1].first = 1;
    
    while(!q.empty()){
        auto [x,y,b] = q.front();
        q.pop();
        
        if(x == N && y == M){
            return visit[N][M].first;
        }
        
        
        for(int i=0; i<4; ++i){
            
            int tmp_x = x + mx[i];
            int tmp_y = y + my[i];
            
            if(isin(tmp_x, tmp_y)){
                
                if(v[tmp_x][tmp_y]){ // block
                    
                    if(!b && visit[tmp_x][tmp_y].first > visit[x][y].first+1){
                        q.push({tmp_x, tmp_y, true});
                        visit[tmp_x][tmp_y].first = visit[x][y].first+1;
                        visit[tmp_x][tmp_y].second = true;
                    }
                }
                else{ // no block
                    
                    if(!b && visit[tmp_x][tmp_y].second){
                        q.push({tmp_x, tmp_y, false});
                        visit[tmp_x][tmp_y].first = visit[x][y].first + 1;
                        visit[tmp_x][tmp_y].second = false;
                    }
                    else if(visit[tmp_x][tmp_y].first > visit[x][y].first + 1){
                        q.push({tmp_x, tmp_y, b});
                        visit[tmp_x][tmp_y].first = visit[x][y].first + 1;
                        visit[tmp_x][tmp_y].second = b;
                    }
                }

            }
        }
    }
    return -1;
}




int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    char input;
    cin >> N >> M;
    
    for(int i=1; i<=N; ++i)
        for(int j=1; j<=M; ++j){
            cin >> input;
            v[i][j] = '0' - input;
        }
    
    cout << bfs();
    
    return 0;
}
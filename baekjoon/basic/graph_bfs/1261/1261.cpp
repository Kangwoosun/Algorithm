#include <iostream>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

int visit[101][101];
bool v[101][101];

int N, M;
int mx[] = {0,0,-1,1};
int my[] = {1,-1,0,0};

bool isin(int x, int y){
    return (1<=x && x<=N && 1<=y && y<=M ? true : false);
}


int bfs(){
    
    queue<pair<int,int>> q;
    
    for(int i =1; i<=N; ++i)
        for(int j = 1; j<=M; ++j)
            visit[i][j] = INT_MAX;
    
    q.push(make_pair(1,1));
    visit[1][1] = 0;
    
    while(!q.empty()){
        
        auto [x,y] = q.front();
        q.pop();
        
        if(x == N && y == M)
            continue;
            
        for(int i =0; i<4; ++i){
            
            int tmp_x = x + mx[i];
            int tmp_y = y + my[i];
            
            if(v[tmp_x][tmp_y]){
                if(isin(tmp_x, tmp_y) && visit[tmp_x][tmp_y]>visit[x][y]+1){
                    q.push(make_pair(tmp_x, tmp_y));
                    visit[tmp_x][tmp_y] = visit[x][y] + 1;
                }
            }
            else{
                if(isin(tmp_x,tmp_y) && visit[tmp_x][tmp_y] > visit[x][y]){
                    q.push(make_pair(tmp_x,tmp_y));
                    visit[tmp_x][tmp_y] = visit[x][y];
                }
            }
            
        }
        
    }
    
    return visit[N][M];
}


int main(){
    
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    char input;
    cin >> M >> N;
    
    
    for(int i =1; i<= N; ++i){
        for(int j=1; j<=M; ++j){
            
            cin >> input;
            v[i][j] = '0' - input;
        }
    }
    
    
    cout << bfs();
    
    
}
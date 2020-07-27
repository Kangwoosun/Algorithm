#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;

int h[51][51];
bool visit[51][51];

int N, M;

bool isin(int x, int y){
    
    return (0<=x && x < N && 0<=y && y<M ? true : false);
    
}
int mx[] = {-1, +1, 0, 0, -1, -1, +1, +1};
int my[] = {0, 0, -1, +1, -1, +1, -1, +1};


int bfs(int x, int y){
    
    visit[x][y] = true;
    
    
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    
    
    while(!q.empty()){
        
        auto [_x, _y] = q.front();
        q.pop();
        
        for(int i =0; i<8; ++i){
            int row = _x+mx[i];
            int column = _y +my[i];
            
            if(isin(row, column) && h[row][column] && !visit[row][column]){
                visit[row][column] = true;
                q.push(make_pair(row,column));
            }
            
        }
        
        
        
        /*
        if(isin(_x-1, _y))
            if(h[_x-1][_y])
                if(!visit[_x-1][_y]){
                    visit[_x-1][_y] = true;
                    q.push(make_pair(_x-1,_y));
                }
        if(isin(_x+1, _y))
            if(h[_x+1][_y])
                if(!visit[_x+1][_y]){
                    visit[_x+1][_y] = true;
                    q.push(make_pair(_x+1,_y));
                }
        if(isin(_x, _y-1))
            if(h[_x][_y-1])
                if(!visit[_x][_y-1]){
                    visit[_x][_y-1] = true;
                    q.push(make_pair(_x,_y-1));
                }
        if(isin(_x, _y+1))
            if(h[_x][_y+1])
                if(!visit[_x][_y+1]){
                    visit[_x][_y+1] = true;
                    q.push(make_pair(_x,_y+1));
                }
                
        if(isin(_x-1, _y-1))
            if(h[_x-1][_y-1])
                if(!visit[_x-1][_y-1]){
                    visit[_x-1][_y-1] = true;
                    q.push(make_pair(_x-1,_y-1));
                }
                
        if(isin(_x-1, _y+1))
            if(h[_x-1][_y+1])
                if(!visit[_x-1][_y+1]){
                    visit[_x-1][_y+1] = true;
                    q.push(make_pair(_x-1,_y+1));
                }
                
        if(isin(_x+1, _y+1))
            if(h[_x+1][_y+1])
                if(!visit[_x+1][_y+1]){
                    visit[_x+1][_y+1] = true;
                    q.push(make_pair(_x+1,_y+1));
                }
                
        if(isin(_x+1, _y-1))
            if(h[_x+1][_y-1])
                if(!visit[_x+1][_y-1]){
                    visit[_x+1][_y-1] = true;
                    q.push(make_pair(_x+1,_y-1));
                }
        */
    }
    
    
    return 1;
    
}


int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int input;
    int count = 0;
    
    while(true){
        cin >> M >> N;
        count = 0;
        if(N==0 && M==0)
            break;
        
        for(int i =0; i<N; ++i){
            for(int j =0; j<M; ++j){
                cin >> input;
                h[i][j] = input;
            }
        }
        
        for(int i =0; i<N; ++i)
            for(int j =0; j<M; ++j)
                if(h[i][j])
                    if(!visit[i][j])
                        count += bfs(i,j);
                    
        
        cout << count << '\n';
        memset(visit, 0, sizeof(visit));
        
    }
    return 0;
}
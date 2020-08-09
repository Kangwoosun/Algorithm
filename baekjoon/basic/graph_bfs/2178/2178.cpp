#include <iostream>
#include <queue>
#include <utility>
using namespace std;


int v[101][101];
bool visit[101][101];
int mx[] = { 0, 0, -1, +1};
int my[] = { 1, -1, 0, 0};
int N, M;

bool isin(int x, int y){
    return (1<=x && x<=N && 1<= y && y<=M);
}

class node{
public:
    node(int x, int y, int depth):x(x), y(y), depth(depth){};
    int x;
    int y;
    int depth;
};


int bfs(int x, int y){
    
    node* tmp = new node(x,y,1);
    
    int count = 0;
    visit[x][y] = true;
    queue<node*> q;
    
    q.push(tmp);
    
    while(!q.empty()){
        
        tmp = q.front();
        q.pop();
        
        count = tmp->depth;
        if(tmp->x == N && tmp->y == M)
            break;
        
        for(int i =0; i<4; ++i){
            
            int _x = tmp->x + mx[i];
            int _y = tmp->y + my[i];
            
            if(isin(_x, _y) && v[_x][_y] && !visit[_x][_y]){
                visit[_x][_y] = true;
                q.push(new node(_x, _y, tmp->depth + 1));
            }
            
            
        }
        
        delete tmp;
    }
    
    return count;
    
}




int main(){
    int count;
    char input;
    cin >> N >> M;
    
    
    for(int i =1; i<=N; ++i){
        
        for(int j =1; j<=M; ++j){
            cin >> input;
            v[i][j] = '0' - input;
        }
    }
    
    
    count = bfs(1,1);
    
    cout << count;
    
    return 0;
}
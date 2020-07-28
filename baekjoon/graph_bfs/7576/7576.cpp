#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <climits>
#include <cstring>
using namespace std;

int N, M;
int v[1001][1001];
bool visit[1001][1001];
int mx[] = {0, 0, 1, -1};
int my[] = {1, -1, 0, 0};


class node{
public:
    node(int x, int y, int depth):x(x),y(y),depth(depth){};
    int x;
    int y;
    int depth;
};

queue<node*> q;

bool isin(int x, int y ){
    return (1<=x && x<=N && 1<=y && y<=M ? true : false);
}

int bfs(){
    
    int count = 0;
    node* tmp;
    
    while(!q.empty()){
        tmp = q.front();
        q.pop();
        count = tmp->depth;
        
        for(int i =0; i<4; ++i){
            int _x = tmp->x + mx[i];
            int _y = tmp->y + my[i];
            
            if(isin(_x, _y) && !visit[_x][_y] && v[_x][_y] == 0){
                visit[_x][_y] = true;
                q.push(new node(_x, _y, tmp->depth +1));
            }
        }
        delete tmp;
    }
    
    return count;
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int input;
    int result;
    
    cin >> M >> N;
    
    for(int i =1; i<=N; ++i){
        for(int j =1; j<=M; ++j){
            cin >> input;
            v[i][j] = input;
            if(input == 1)
                q.push(new node(i, j, 0));
        }
    }
    
    result = bfs();
    
    for(int i =1; i<=N; ++i){
        for(int j =1; j<=M; ++j){
            if(v[i][j] == 0){
                if(visit[i][j] == false){
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    
    cout << result;
    return 0;
    
}
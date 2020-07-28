#include <iostream>
#include <utility>
#include <queue>
using namespace std;

int N, M;
int v[1001][1001];
bool visit[1001][1001];
int mx[] = {0, 0, 1, -1};
int my[] = {1, -1, 0, 0};


queue<pair<int,int>> q;

bool isin(int x, int y ){
    return (1<=x && x<=N && 1<=y && y<=M ? true : false);
}

int bfs(){
    
    int count = 0;
    int bef = q.size();
    int cur;
    bool next;
    while(!q.empty()){
        cur = 0;
        next = false;
        for(int i =0; i<bef; ++i){
            
            auto [x,y] = q.front();
            q.pop();
            
            for(int i =0; i<4; ++i){
                int _x = x + mx[i];
                int _y = y + my[i];
                
                if(isin(_x, _y) && !visit[_x][_y] && v[_x][_y] == 0){
                    visit[_x][_y] = true;
                    q.push(make_pair(_x, _y));
                    next = true;
                    cur++;
                }
            }
            
        }
        bef = cur;
        if(next) count++;
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
                q.push(make_pair(i, j));
        }
    }
    
    result = bfs();
    
    for(int i =1; i<=N; ++i){
        for(int j =1; j<=M; ++j){
            if(v[i][j] == 0 && !visit[i][j]){
                cout << -1;
                return 0;
            }
        }
    }
    
    cout << result;
    return 0;
    
}
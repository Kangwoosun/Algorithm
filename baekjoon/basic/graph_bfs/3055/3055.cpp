#include <iostream>
#include <utility>
#include <queue>
using namespace std;

#define BLANK 0
#define WATER 1
#define ROCK 2
#define BIBER 3
#define HEDEGEDOG 4


int R, C;
int X, Y, start_x, start_y;

bool visit[51][51];
int v[51][51];
queue<pair<int,int>> w[2];

int mx[] = {0,0,-1,1};
int my[] = {1,-1,0,0};

bool isin(int x, int y){
    return (1<=x && x<=R && 1<=y&& y<=C ? true : false);
}

struct node{
    int x;
    int y;
    int c;
};


void overflow(){
    
    if(w[0].empty()){
        while (!(w[1].empty())){
            auto [x,y] = w[1].front();
            w[1].pop();
            
            for(int i =0; i<4; ++i){
                int tmp_x = x + mx[i];
                int tmp_y = y + my[i];
                
                if(isin(tmp_x, tmp_y) && v[tmp_x][tmp_y] == BLANK){
                    w[0].push(make_pair(tmp_x, tmp_y));
                    v[tmp_x][tmp_y] = WATER;
                }
            }
            
        }
    }
    
    else{
         while (!(w[0].empty())){
            auto [x,y] = w[0].front();
            w[0].pop();
            
            for(int i =0; i<4; ++i){
                int tmp_x = x + mx[i];
                int tmp_y = y + my[i];
                
                if(isin(tmp_x, tmp_y) && v[tmp_x][tmp_y] == BLANK){
                    w[1].push(make_pair(tmp_x, tmp_y));
                    v[tmp_x][tmp_y] = WATER;
                }
            }
            
        }
    }
    
    return;
}


int bfs(){
    queue<node>q;
    q.push({start_x, start_y, 0});
    visit[start_x][start_y] = true;
    
    int count = -1;
    
    while(!q.empty()){
        
        auto [x,y,c] = q.front();
        q.pop();
        if(v[x][y] == BIBER)
            return c;
        
        if(count != c){
            count = c;
            overflow();
        }
        for(int i =0; i<4; ++i){
            int tmp_x = x + mx[i];
            int tmp_y = y + my[i];
            
            if(isin(tmp_x, tmp_y) && (v[tmp_x][tmp_y] == BLANK || v[tmp_x][tmp_y] == BIBER) && !visit[tmp_x][tmp_y] ){
                q.push({tmp_x, tmp_y, c+1});
                visit[tmp_x][tmp_y] = true;
            }
            
        }
        
    }
    
    return -1;
}



int main(){
    
    int result;
    char input;
    cin >> R >> C;
    
    
    for(int i = 1; i<= R; ++i){
        for(int j =1; j<= C; ++j){
            cin >> input;
            
            if(input == '.'){
                v[i][j] = BLANK;
            }
            else if(input == '*'){
                v[i][j] = WATER;
                w[0].push(make_pair(i,j));
            }
            else if(input == 'X'){
                v[i][j] = ROCK;
            }
            else if(input == 'D'){
                v[i][j] = BIBER;
            }
            else if(input == 'S'){
                v[i][j] = BLANK;
                start_x = i;
                start_y = j;
            }
        }
    }
    
    result = bfs();
    if(result != -1)
        cout << result;
        
    else
        cout << "KAKTUS";
}
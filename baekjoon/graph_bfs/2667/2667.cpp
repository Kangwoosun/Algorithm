#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

int h[25][25];
bool visit[25][25];

int N;

bool isin(int x, int y){
    
    return (0<=x && x < N && 0<=y && y<N ? true : false);
    
}



int bfs(int x, int y){
    
    visit[x][y] = true;
    int count=0;
    
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    
    
    while(!q.empty()){
        
        auto [_x, _y] = q.front();
        q.pop();
        count++;
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
    }
    
    
    
    
    
    return count;;
    
}


int main(){
    
    char input;
    int count = 0;
    vector<int> v;
    cin >> N;
    
    for(int i =0; i<N; ++i){
        for(int j =0; j<N; ++j){
            cin >> input;
            h[i][j] = '0'-input;
        }
    }
    
    for(int i =0; i<N; ++i)
        for(int j =0; j<N; ++j)
            if(h[i][j])
                if(!visit[i][j]){
                    v.push_back(bfs(i,j));
                    count++;
                }
    
    
    sort(v.begin(), v.end());
    
    cout << count << '\n';
    for(auto& e : v){
        cout << e << '\n';
    }
        
}
#include <iostream>
#include <utility>
#include <climits>
#include <queue>
using namespace std;

int S;
bool visit[1001][1001];

bool isin(int x){
    return (1 <= x && x <= 1000 ? true : false);
}
 
struct Node{
    Node(int x, int y, int z):value(x),count(y), save(z){}
    int value;
    int count;
    int save;
};

int bfs(){
    
    int tmp_x, tmp_s;
    queue<Node*> q;
    q.push(new Node(1,1,1));
    visit[1][1] = true;
    
    while(!q.empty()){
        
        Node* tmp = q.front();
        q.pop();
        
        int x = tmp->value;
        int c = tmp->count;
        int s = tmp->save;
        
        //cout << x << ' ' << s << ' ' << c << endl; 
        
        if(x == S){
            return c;
        }
        
        for(int i =0; i<3; ++i){
            
            switch(i){
                
            case 0: // paste
                tmp_x = x+s;
                tmp_s = s;
                break;  
                
            case 1: // copy
                tmp_x = x;
                tmp_s = x;
                break;
                
            case 2: // -1
                tmp_x = x-1;
                tmp_s = s;
                break;
            }
            
            if(isin(tmp_x)&&!visit[tmp_x][tmp_s]){
                q.push(new Node(tmp_x, c+1, tmp_s));
                visit[tmp_x][tmp_s] = true;
            }
            
        }
        delete tmp;
    }
    
    return -1;
}

int main(){
    
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> S;
    
    cout << bfs();
    
    return 0;
}
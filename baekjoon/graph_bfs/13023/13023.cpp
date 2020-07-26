#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> relationship[2000];
bool visit[2000];

int DFS(int start, int count){
    
    
    if(count == 5){
        cout << '1';
        exit(0);
    }
    
    visit[start] = true;
    
    for(int i =0; i<relationship[start].size(); ++i){
        if(!visit[relationship[start][i]])
            DFS(relationship[start][i], count+1);
    }
    
    visit[start] = false;
    
    return 0;
    
}


int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, M, input1, input2;
    
    
    cin >> N >> M;
    
    
    for(int i =0; i<M; ++i){
        
        cin >> input1 >> input2;
        relationship[input1].push_back(input2);
        relationship[input2].push_back(input1);
    }
    
    for(int i =0; i<M; ++i){
        DFS(i,1);
    }
    
    cout << '0';
    
    
    return 0;
}
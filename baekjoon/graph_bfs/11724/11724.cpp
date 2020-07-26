#include <iostream>
#include <vector>
using namespace std;


vector<int> v[1001];
bool visit[1001];

void dfs(int start){
    
    visit[start] = true;
    
    for(auto i: v[start]){
        if(!visit[i])
            dfs(i);
    }
    
}

int main(){
    
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, M, count = 0;
    int a, b;
    cin >> N >> M;

    for(int i = 0; i < M; ++i){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    for(int i = 1; i<=N; ++i){
        if(!visit[i]){
            dfs(i);
            count++;
        }
    }

    cout << count;
    return 0;
}
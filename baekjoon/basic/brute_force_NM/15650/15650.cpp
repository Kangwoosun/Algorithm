#include <iostream>
#include <vector>
using namespace std;


vector<int> v;
bool check[10];

int N, M;

void _print(){
    
    for(int i =0; i<N; ++i){
        if(check[i])
            cout << v[i] << ' ';
    }
    cout << '\n';
    return;
}
void combination(int idx, int r, int depth){
    
    if(depth == r){
        _print();
        return;
    }
    
    for(int i = idx; i<N; ++i){
        
        if(check[i]) continue;
        
        check[i]=true;
        combination(i, r, depth+1);
        check[i]=false;
    }
    
    return;
}

int main(){
    
    cin >> N >> M;
    
    for(int i =1; i<=N; ++i){
        v.push_back(i);
    }
    
    combination(0, M, 0);
    
    return 0;
    
}
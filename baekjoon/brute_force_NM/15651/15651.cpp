#include <iostream>
#include <vector>
using namespace std;


int N, M;
int v[10];
int arr[10];
void Print(){
    
    for(int i =0; i<M; ++i){
        cout << arr[i] << ' ';
    }
    
    cout << endl;
    return;
}


void combination(int idx, int r, int depth){
    
    if(depth == r){
        Print();
        return;
    }
    
    for(int i =0; i<N; ++i){
        
        
        arr[depth] = v[i];
        combination(i, r, depth+1);
        
    }
    return;
    
}

int main(){
    
    
    cin >> N >> M;
    for(int i=0; i<N; ++i){
        v[i] = i+1;
    }
    
    combination(0,M,0);
    
    return 0;
    
}
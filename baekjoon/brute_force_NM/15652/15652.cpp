#include <iostream>
using namespace std;


int arr[10] = {0,};

void Print(int depth){
    for(int i =0; i<depth; ++i){
        cout << arr[i] << ' ';
    }
    cout << '\n';
}


void combination(int n, int r, int idx, int depth){
    
    if(depth == r){
        Print(depth);
        return;
    }
    
    for(int i = idx; i<n; ++i){
        
        arr[depth] = i+1;
        combination(n, r, i, depth+1);
        
    }
    
    return;
}


int main(){
    
    int N, M;
    cin >> N >> M;
    
    combination(N, M, 0, 0);

    
}
#include <iostream>
#include <vector>
using namespace std;


int N, M;

int arr[10];

void combination(int r, int depth){
    
    if(depth == r){
            for(int i =0; i<r; ++i){
                cout << arr[i] << ' ';
            }
        
        cout << '\n';
        return;
    }
    
    for(int i =0; i<N; ++i){

        arr[depth] = i+1;
        combination(r, depth+1);
    }
    return;
}

int main(){
    
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    
    combination(M,0);
    
    return 0;
    
}
#include <iostream>
#include <vector>
using namespace std;


vector<int> v[20001];

int main(){
        
    int K, V, E;
    int a, b;
    cin >> K;
    
    for(int i=0;i<K;++i){
        cin >> V >> E;
        
        for(int j=0; j<E;++j){
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
    }
    
}
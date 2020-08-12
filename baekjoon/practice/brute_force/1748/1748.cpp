#include <iostream>
#include <string>
using namespace std;

int main(){
    int N,count = 0;
    int i,idx = 0;
    
     cin >> N;
    
    for(i =10; i<=N; i*=10){
        idx++;
        
        count += idx *i/10*9;
    }
    idx++;
    
    i /= 10;
    count += (N-i+1)*idx;
    
    cout << count;
    
    return 0;
}
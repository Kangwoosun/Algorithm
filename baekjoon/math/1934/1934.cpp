#include <iostream>
using namespace std;

int main(){
    
    int T, A, B;
    
    int tmp, low, high, gcd, lcd;
    
    cin >> T;
    
    for (int i =0; i<T; i++){
        cin >> A >> B;
        
        if(A < B){
            low = A;
            high = B;
        }
        else{
            low = B;
            high = A;
        }
        
        
        while(low != 0){
            
            high %= low;
            
            tmp = low;
            low = high;
            high = tmp;
            
        }
        
        gcd = high;
        lcd = A*B/gcd;
        
        cout << lcd << '\n';
        
    }
    
    
    return 0;
}
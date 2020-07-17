#include <iostream>
using namespace std;


int main(){
    
    int input1, input2, gcd, lcd;
    cin >> input1 >> input2;
    
    int low, high, tmp;
    
    
    if(input1 == input2){
        gcd = input1;
        lcd = input1;
    }
    else{
        
        if(input1 > input2){
            low = input2;
            high = input1;
        }
        else{
            low = input1;
            high = input2;
        }
        while(low != 0){
            
            high %= low;
            
            tmp = low;
            low = high;
            high = tmp;
            
        }
        
        gcd = high;
        lcd = gcd * (input1/gcd) * (input2/gcd);
        
    }
    
    cout << gcd << endl;
    cout << lcd << endl;
    
    return 0;
    
}

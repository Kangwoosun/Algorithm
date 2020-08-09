#include <iostream>
using namespace std;



int factorial(int n ){
    
    int result = 1;
    
    for (int i =1; i <= n; i++){
        result *= i;
    }
    
    return result;
    
}



int main(){
    
    int T, N, sum;
    
    int three, two, one;
    
    
    cin >> T;
    
    for (int i =0; i<T; ++i){
        
        sum = 0;
        
        cin >> N;
        
        three = N/3;
        two = (N%3)/2;
        one = (N%3)%2;
        
        
        while(1){
            
            while(1){
                
                
                sum += factorial(three+two+one) / factorial(three) / factorial(two) / factorial(one);
                
                
                if( two == 0)
                    break;
                
                --two;
                one += 2;
            }
            
            if(three == 0)
                break;
                
            --three;
            two = (N - 3*three) /2;
            one = (N - 3*three) %2;
            
        }
        
        cout << sum << endl;
        
    }
    
    
    
    
    
    return 0;
    
}
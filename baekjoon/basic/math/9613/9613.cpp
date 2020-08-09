#include <iostream>
using namespace std;

int input[200];


int main(){
    
    int t, n, low, high, tmp;
    long long sum_gcd;
    cin >> t;
    
    for (int i =0; i<t; ++i){
        
        sum_gcd = 0;
        
        cin >> n;
        
        
        for (int j=0; j<n; ++j){
            
            cin >> input[j];
            
        }
        
        
        for (int j =0; j<n-1; ++j){
            
            for (int k=j+1; k<n; ++k){
                
                if (input[j] < input[k]){
                    low = input[j];
                    high = input[k];
                }
                else{
                    low = input[k];
                    high = input[j];
                }
                
                while(low != 0){
                    high %= low;
                    
                    tmp = low;
                    low = high;
                    high = tmp;
                    
                }
                
                sum_gcd += high;
                
            }
            
            
        }
        
        cout << sum_gcd << '\n';
        
        
        
        
    }
    
    
    
    return 0;
    
}
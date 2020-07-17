#include <iostream>
#include <vector>
using namespace std;


int is_not_prime[1000001];

int main(){
    
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    vector<int> v;
    int n, prime1, prime2;
    
    
    for(int i =2; i*i <= 1000000; ++i){
        if(!is_not_prime[i]){
            v.push_back(i);
            for(int j = i*i; j<=1000000; j+=i)
                is_not_prime[j] = 1;
        }
    }
    
    
    while(cin >> n){
        
        
        if (n == 0)
            break;
        
        prime1 = 0;
        prime2 = 0;
        
        
        for(auto& prime : v){
            
            if(prime <= n/2){
                
                if(!is_not_prime[n-prime]){
                    prime1 = prime;
                    prime2 = n-prime;
                    break;
                }
                
                
            }
            
        }
        
        
        if(prime1 != 0){
            
            cout << n << " = " << prime1 << " + " << prime2 << '\n';
            
        }
        
        else{
            
            cout << "Goldbach's conjecture is wrong." << '\n';
            
        }
        
        
    }
    
    
    return 0;
}
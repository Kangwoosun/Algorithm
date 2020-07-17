#include <iostream>
using namespace std;

int main(){
    
    int N, input, count = 0;
    bool decimal;
    
    
    cin >> N;
    
    for(int i =0; i<N; ++i){
        
        cin >> input;
        
        decimal = true;
        
        if(input == 1)
            continue;
        
        
        for(int j=2; j<input; ++j){
            if(!(input%j)){
                decimal = false;
                break;
            }
        }
        
        
        if (decimal)
            count += 1;
        
        
    }
    
    cout << count << endl;
    
    
    
    return 0;
}
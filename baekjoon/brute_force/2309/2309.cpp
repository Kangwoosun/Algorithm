#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    
    
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    
    int input, sum = 0;
    vector<int> v;
    
    for(int i =0; i<9; i++){
        
        cin >> input;
        sum += input;
        v.push_back(input);
        
    }
    
    sort(v.begin(), v.end());
    
    for(int i =0; i<8; i++){
        
        for(int j =i+1; j<9; j++){
            
            if((sum - v[i] - v[j]) == 100){
                
                v.erase(v.begin()+j);
                v.erase(v.begin()+i);
                break;
            }
            
        }
        
    }
    
    
    for(auto& e:v){
        cout << e << endl;   
    }
    
    
    
    
    return 0;
}
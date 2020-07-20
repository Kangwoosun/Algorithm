#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


vector<int> v;

int main(){
    
    int N, input, base, min = INT_MAX;
    vector<int>::iterator index;
    vector<int> t;
    
    cin >> N;
    
    for(int i =0; i<N; i++){
        cin >> input;
        v.push_back(input);
    }
    
    for(auto iter = v.end(); iter != v.begin(); --iter){
        
        if(*(iter-1) < *(iter)){
            
            base = *(iter-1);
            t.assign(iter-1, v.end());
            v.erase(iter-1, v.end());
            
            
            for(auto iter2 = t.begin()+1; iter2 != t.end(); ++iter2){
                
                if(base < *iter2 && *iter2 < min){
                    min = *iter2;
                    index = iter2;
                }
                
            }
            
            int tmp = *index;
            *index = *(t.begin());
            *(t.begin()) = tmp;
            
            sort(t.begin()+1, t.end());
            
            v.insert(v.end(), t.begin(), t.end());
            
            for(auto& i: v){
                cout << i << " ";
            }
            
            
            return 0;
        }
        
    }
    
    cout << "-1";
    
    return 0;
}
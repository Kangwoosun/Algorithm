#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdlib>
using namespace std;

int main(){
    
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N, base, min, index = 0, max=0, sum, input;
    bool check;
    vector<int> v, t;
    
    cin >> N;
    
    for(int i = 0; i<N; ++i){
        cin >> input;
        v.push_back(input);
    }
    
    sort(v.begin(), v.end());
    
    
    
    while(1){
        
        check = false;
        min = INT_MAX;
        sum = 0;
        
        
        for(int i = v.size()-1; i>0; --i){
            
            if(v[i-1] < v[i]){
                
                base = v[i-1];
                t.assign(v.begin()+i-1, v.end());
                v.erase(v.begin()+i-1, v.end());
                
                for(int j = 1; j<t.size(); ++j){
                    
                    if(base < t[j] && t[j] < min){
                        min = t[j];
                        index = j;
                    }
                    
                }
                
                int tmp = t[index];
                t[index] = t[0];
                t[0] = tmp;
                
                sort(t.begin()+1, t.end());
                
                v.insert(v.end(), t.begin(), t.end());
                
                check = true;
                
                for(int j =0; j<v.size()-1; ++j)
                    sum += abs(v[j] - v[j+1]);
                
                if (sum > max)
                    max = sum;
                
                
                
                break;
                
            }
            
        }
        
        
        if (check)
            continue;
        else
            break;
        
    }
    
    cout << max;
    
    return 0;
    
    
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


int N, base, min, index = 0 ,input;
int oper[4], A[12];
long long result_max = INT_MIN, result_min = INT_MAX, result;


bool _check[11];

void calc(){
    
    bool check;
    
    vector<int> v, t;
    
    for(int i =0; i<N; ++i){
        if(_check[i] == true)
            v.push_back(i);
    }
    
    while(1){
        
        result = A[0];
    
        check = false;
        min = INT_MAX;
        
        for(int i =0; i<N-1; i++){
            
            
            switch(v[i]){
            
            case 0:
                result += A[i+1];
                break;
            case 1:
                result -= A[i+1];
                break;
            case 2: 
                result *= A[i+1];
                break;
            case 3:
                result /= A[i+1];
                break;
            default:
                break;
            }
            
        }
        
        if(result < result_min)
            result_min = result;
        
        if(result > result_max)
            result_max = result;
        
        
        
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
                
                break;
                
            }
            
        }
        
        
        if (check)
            continue;
        else
            break;
        
        
        
    }
    
        
}


void combination(int idx, int cur){
    
    if(cur == N-1){
        calc();
        return;
    }
    
    for(int i = idx; i<N; i++){
        
        
        
        
    }
    
}


int main(){
    
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    
    cin >> N;
    
    for(int i = 0; i<N; ++i){
        cin >> input;
        A[i] = input;
    }
    
    for(int i =0; i<4; ++i){
        cin >> input;
        oper[i] = input;
    }
    /*
     * [0] = +
     * [1] = -
     * [2] = *
     * [3] = /
     */
    
    combination(0,0);
    
    
    
    cout << result_max << endl;
    cout << result_min;
    
    return 0;
}
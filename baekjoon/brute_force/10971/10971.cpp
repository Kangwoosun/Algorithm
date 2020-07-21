#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;



int W[10][10];

int main(){
    
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N, base, min, input,index = 0;
    bool check;
    int min_weight = INT_MAX;
    long long sum;
    vector<int> v, t;
    
    cin >> N;
    
    for (int i =0; i< N; ++i){
        for(int j =0; j< N; ++j){
            
            cin >> input;
            W[i][j] = input;
            
        }
    }
    
    for(int i = 0; i<N; ++i){
        v.push_back(i);
    }
    
    while(1){
        
        check = false;
        min = INT_MAX;
        sum = 0;
        
        
        for(int i = 0; i<N-1; ++i){
            
            if(W[v[i]][v[i+1]] == 0){
                sum = INT_MAX;
                break;
            }
            sum += W[v[i]][v[i+1]];
        }
        if(W[v[N-1]][v[0]] != 0){
            sum += W[v[N-1]][v[0]];
            if(sum < min_weight)
                min_weight = sum;
        }
        
            
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
    
    cout << min_weight;
    
    return 0;
}

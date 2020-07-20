#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(int a, int b) {
    return a > b;
}

int main(){
    
    int N, input, index= 0, basic, max=0;
    vector<int> v, t;
    cin >> N;
    
    for(int i = 0; i<N; i++){
        cin >> input;
        v.push_back(input);
    }
    
    
    for(int i = v.size()-1; i > 0; --i){
        if(v[i-1] > v[i]){
            
            basic = v[i-1];
            t.assign(v.begin()+i-1, v.end());
            v.erase(v.begin()+i-1, v.end());
            
            
            for(int j =1; j < t.size(); ++j){
                
                if(basic > t[j] && max < t[j]){
                    max = t[j];
                    index = j;
                }
            }
            
            int tmp = t[index];
            t[index] = t[0];
            t[0] = tmp;
            
            sort(t.begin()+1, t.end(), comp);
            
            v.insert(v.end(), t.begin(), t.end());
            
            for(auto& i : v){
                cout << i << ' ';
            }
            
            
            
            
            
            return 0;
            
        }
    }
    
    
    cout << "-1";
    
    
    
    return 0;
}
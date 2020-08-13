#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

char comp[10];
vector<int> v;
int k, large = -1, small = INT_MAX;
string large_str, small_str;

void permutation(int start, int end){
    
    if(start == end){
        bool check = true;
        for(int i=1; i<=k;++i){
            switch(comp[i]){
            case '<':
                if(v[i-1] > v[i])
                    check = false;
                break;
            case '>':
                if(v[i-1] < v[i])
                    check = false;
                break;
            default:
                break;
            }
            if(!check)
                break;
        }
        
       
        if(check){
            string tmp = "";
            int comp;
            for(int i =0; i<=k; ++i){
                tmp += to_string(v[i]);
            }
            comp = stoi(tmp);
            
            
            if(comp > large){
                large_str.clear();
                large_str.assign(tmp);
                large = comp;
                
                for(auto& e : v){
                    cout << e << ' ';
                }
                cout << endl;
                cout << large << ' ' << large_str << ' ' << small << ' ' << small_str << endl;
                
            }
            
            if(comp < small){
                small_str.clear();
                small_str.assign(tmp);
                small = comp;
                
                for(auto& e : v){
                    cout << e << ' ';
                }
                cout << endl;
                cout << large << ' ' << large_str << ' ' << small << ' ' << small_str << endl;
                
            }
        }
        
        return;
    }
    else{
        for(int i = start; i<=end; ++i){
            swap(v[start],v[i]);
            
            permutation(start+1, end);
            
            swap(v[start],v[i]);
        }
    }
    
    return;
}


int main(){

    cin >> k;
    
    for(int i = 1; i<=k; ++i){
        cin >> comp[i];
    }
    
    for(int i =0; i<=9; ++i)
        v.push_back(i);
       
    permutation(0, v.size()-1);
    
    cout << large_str << '\n';
    cout << small_str;
    
    return 0;
}
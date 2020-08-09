#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

vector<int> v;
int arr[10];
bool check[10];

void swap(int& a, int& b){
    int tmp;
    
    tmp = a;
    a = b;
    b = tmp;
    
    return;
}

void _print(int depth){
    for(int i =0; i<depth; ++i)
            cout << arr[i] << ' ';
    cout << '\n';
    return;
}

void permutation2(){
    
    int base, min, index = 0;
    bool check;
    vector<int> t;
    
    
    while(1){
        
        check = false;
        min = INT_MAX;
        
        for(auto& e: v)
            cout << e << " ";
        
        cout << '\n';
        
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

void permutation(int n, int r, int depth){
    
    if(r == depth){
        _print(depth);
        return;
    }
    
    for(int i = 0; i<n; ++i){
        
        if(check[i] == true) continue;
        check[i] = true;
        arr[depth] = v[i];
        permutation(n, r, depth+1);
        check[i] = false;
    }
    
    return;    
}

int main(){
    
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, M;
    
    cin >> N >> M;
    
    
    for(int i =1; i<=N; ++i){
        v.push_back(i);
    }
    
    
    if(N>M)
        permutation(N, M, 0);
    else
        permutation2();
    
    
    return 0;
}
#include <iostream>
#include <string>
#include <climits>
using namespace std;

char comp[10];
vector<int> v;
int k;
long long large = -1, small = 9999999999;
string large_str, small_str;

void permutation(int start, int end){
    
    if(start == end){
    
        
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
    string input;
    
    cin >> k;
    
    for(int i =0 ; i<k; ++i){
        cin >> input;
    }
    
    for(int i =0; i<=9; ++i)
        v.push_back(i);
       
    permutation(0, v.size()-1);
    
    cout << large_str << '\n';
    cout << small_str;
    
    return 0;
}
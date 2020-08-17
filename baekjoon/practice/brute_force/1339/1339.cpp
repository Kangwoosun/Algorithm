#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

pair<int,bool> store[26];
vector<int> v;
vector<string> s;
int N;
int large = -1;

int make_int(string str_){
    
    string tmp = "";
    
    for(auto& e : str_){
        tmp += to_string(store['A'-e].first);
    }
    
    return stoi(tmp);
}



void permutation(int start, int end){
    
    if(start == end){
        
        int count = 0, result = 0;
        for(int i = 0; i<26; ++i){
            if(store[i].second){
                
                store[i].first = v[count];
                count++;
            }
        }
        
        for(auto& i : v){
            cout << i << ' ';
        }
        cout << endl;
        for(int i =0; i<N; ++i)
            result += make_int(s[i]);
        
        if(large < result)
            large = result;
        cout << large << endl;
        
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
    
    cin >> N;
    
    for(int i =0 ; i<N; ++i){
        cin >> input;
        s.push_back(input);
        
        for(int j = 0; j<input.size(); ++j){
            store['A'-input[j]].second = true;
        }
        
    }
    
    for(int i =0; i<=9; ++i){
        v.push_back(i);
    }
    
    permutation(0, v.size()-1);
    
    cout << large;
    
    return 0;
}
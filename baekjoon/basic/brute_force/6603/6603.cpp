#include <iostream>
#include <vector>
using namespace std;

#define R 6



std::vector<int> s;
std::vector<bool> check;

void print(){
    
    for(int i = 0; i<s.size(); ++i){
        if(check[i] == true)
            cout << s[i] << ' ';
    }
    cout << '\n';
    
}

void combination(int idx, int cur){
    
    if(cur == R){
        print();
        return;
    }
    for(int i =idx; i<s.size(); ++i){
        if(check[i] == true) continue;
        
        check[i] = true;
        
        combination(i,cur+1);
        
        check[i] = false;
        
    }    

}



int main(){
    
    
    int k, input;
    bool chk = false;
    
    
    while(1){
        
        cin >> k;
        
        
        if(k == 0)
            break;
        
        if (chk)
            cout << "\n";
        else
            chk = true;
            
        for(int i =0; i<k; ++i){
            cin >> input;
            
            s.push_back(input);
            check.push_back(false);
        }
        
        combination(0, 0);
        
        s.clear();
        check.clear();
    }
    
    
    return 0;
}
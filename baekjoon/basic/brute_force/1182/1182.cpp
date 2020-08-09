#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;


int S, counting = 0;

std::vector<int> s;
std::vector<bool> check;




void print(){
    
    int sum = 0;
    
    std::vector<int> tmp;
    
    
    for(int i = 0; i<s.size(); ++i){
        if(check[i] == true){
            sum += s[i];
        }
    }
    if(sum == S)
        counting++;
    
    return;
    
    
}

void combination(int idx, int cur, int deep){
    
    if(cur == deep){
        print();
        return;
    }
    for(int i =idx; i<s.size(); ++i){
        if(check[i] == true) continue;
        
        check[i] = true;
        
        combination(i,cur+1, deep);
        
        check[i] = false;
        
    }    

}



int main(){
    
    
    int N;
    int input;
    
    
    cin >> N >> S;
    
    for(int i = 0; i < N; ++i){
        
        cin >> input;
        
        s.push_back(input);
        check.push_back(false);
    }
    
    
    sort(s.begin(), s.end());
    
    for(int i =1; i<=N; ++i)
        combination(0, 0, i);
    
    
    cout << counting;
    
    return 0;
}
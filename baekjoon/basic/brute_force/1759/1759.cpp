#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;


int L;

int alphabet[26];

std::vector<char> s;
std::vector<bool> check;




void print(){
    
    int vowel = 0;
    int consonant = 0;
    std::vector<char> tmp;
    
    
    for(int i = 0; i<s.size(); ++i){
        if(check[i] == true){
            tmp.push_back(s[i]);
            alphabet[s[i]-'a']++;
        }
    }
    
    
    for(int i =0; i<26; ++i){
        
        switch(i){
            case 0:
            case 4:
            case 8:
            case 14:
            case 20:
                if(alphabet[i] == 1)
                    vowel++;
            break;
            
            default:
                if(alphabet[i] == 1)
                    consonant++;
            break;
        }
    }
    
    
    if(vowel>=1 && consonant >= 2){
        
        for(auto& e : tmp){
            cout << e;
        }
        cout << '\n';
    }
    
    memset(alphabet, 0, sizeof(alphabet));
    return;
    
    
}

void combination(int idx, int cur){
    
    if(cur == L){
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
    
    
    int C;
    char input;
    
    
    cin >> L >> C;
    
    for(int i = 0; i < C; ++i){
        
        cin >> input;
        
        s.push_back(input);
        check.push_back(false);
    }
    
    
    sort(s.begin(), s.end());
    /*
    for(auto& i : s){
        cout << i << ' ';
    }
    cout << endl;
    */
    combination(0, 0);
    
    
    
    
    return 0;
}
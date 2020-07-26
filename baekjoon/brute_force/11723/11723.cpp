#include <iostream>
#include <string>

using namespace std;

int main(){
    
    
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int M, S[21] = {0,}, x;
    string command;
    
    cin >> M;
    
    for(int i =0; i<M; i++){
        
        cin >> command;
       
        if (command == "add"){
            cin >> x;
            S[x] = 1;
        }
        
        else if (command == "remove"){
            cin >> x;
            S[x] = 0;
        }
        
        else if (command == "check"){
            cin >> x;
            
            if(S[x])
                cout << '1' << '\n';
            else
                cout << '0' << '\n';
        }
        
        else if (command == "toggle"){
            cin >> x;
            S[x] ^= 1;
        }
        
        else if (command == "all"){
            
            for(int i =1; i<=20; ++i)
                S[i] = 1;
        }
        
        else if (command == "empty"){
            for(int i =1; i<=20; ++i)
                S[i] = 0;
        }
        
        
    }
    
    
}
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool broken[10];
int min(int a, int b){return a<b?a:b;}

int min_result;

string N;

void find(){
    string str;
    bool check;
    for(int i = 0; i<=1000000; ++i){
        check = false;
        str = to_string(i);
        
        for(int j = 0; j<str.size(); ++j){
            int tmp = str[j] - '0';
            if(broken[tmp]){
                check = true;
                break;
            }
        }
        if(check)
            continue;
        min_result = min(min_result, abs(i - stoi(N))+str.size());
    }
    
    return;
}



int main(){
    
    int M, input;
    cin >> N >> M;
    
    min_result = abs(stoi(N) - 100);
    
    for(int i =0; i<M; ++i){
        cin >> input;
        broken[input] = true;
    }
    
    if(M != 10)
        find();
    
    cout << min_result;
    
    
    return 0;
    
}
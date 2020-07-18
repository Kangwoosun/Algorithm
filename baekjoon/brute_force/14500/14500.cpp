#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int N, M;
vector<vector<pair<int, bool>>> v;

bool is_in(int x, int y){
    return (0<=x && x<N && 0<=y && y<M ? true : false);
}

bool has_been(int x, int y){
    return (v[x][y].second ? true : false);
}

int go_and_check(int x, int y, int deep){
    
    int max = 0, sum = 0, value1, value2, value3, value4;
    
    
    
    if(!is_in(x,y))
        return 0;
    
    if(has_been(x,y))
        return 0;
        
    if (deep == 0)
        return 0;
    
    
    sum += v[x][y].first;
    v[x][y].second = true;
    
    value1 = go_and_check(x-1, y, deep-1);
    value2 = go_and_check(x+1, y, deep-1);
    value3 = go_and_check(x, y-1, deep-1);
    value4 = go_and_check(x, y+1, deep-1);
    
     
    
    if (max < value1)
        max = value1;
        
    if (max < value2)
        max = value2;
    
    if (max < value3)
        max = value3;
        
    if (max < value4)
        max = value4;
    
    sum += max;
    
    v[x][y].second = false;
    
    return sum;
}



int main(){
    
    int input, max = 0, sum, value1, value2, value3, value4;
    
    cin >> N >> M;
    
    v.assign(N,vector<pair<int,bool>>(M,make_pair(0,false)));
    
    
    for(int i =0; i<N; ++i){
        
        for(int j=0; j<M; ++j){
            cin >> input;
            v[i][j].first = input;
        }
    }
    
    for(int i =0; i<N; i++){
        for(int j =0; j<M; j++){
            sum = go_and_check(i, j, 4);
            
            if(max < sum)
                max = sum;
            
            sum = go_and_check(i, j, 1);
            value1 = go_and_check(i-1, j, 1);
            value2 = go_and_check(i+1, j, 1);
            value3 = go_and_check(i, j-1, 1);
            value4 = go_and_check(i, j+1, 1);
            
            sum += value1 + value2 + value3 + value4;
            
            if(max < sum - value1)
                max = sum - value1;
                
            if(max < sum - value2)
                max = sum - value2;
                
            if(max < sum - value3)
                max = sum - value3;
            
            if(max < sum - value4)
                max = sum - value4;
            
        }
    }
    
    
    /*
    for(auto& e : v){
        for(auto& i : e){
            cout << i.first << ' ';
        }
        cout << '\n';
    }
    */
    cout << max;
    
    return 0;
}
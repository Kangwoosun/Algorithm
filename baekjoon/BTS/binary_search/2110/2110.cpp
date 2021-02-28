#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define LOCAL
typedef unsigned long long ull;

vector<int> v, s;

int N, C;


int main(int argc, const char * argv[]) {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif

    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> C;
    int input, max = 0;
    for(int i = 0; i<N; ++i){
        cin >> input;
        v.push_back(input);
    }
    
    sort(v.begin(), v.end());
    
    int left = 1;
    int right = v.back() - v.front();
    int count, cur_idx;
    while(left <= right){
        count = 1;
        cur_idx = 0;
        int middle = (left + right) / 2;
        
        for(int i = 1; i<v.size(); ++i){
            
            if(v[i] - v[cur_idx] >= middle){
                count++;
                cur_idx = i;
            }
        }
        
        
        if(count < C){
            right = middle - 1;
        }
        else{
            if(max < middle)
                max = middle;
            left = middle + 1;
        }
        
        
        
        
    }
    
    cout << max;
    
    return 0;
}

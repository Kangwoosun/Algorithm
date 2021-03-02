#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define LOCAL
typedef long long ll;



int main(int argc, const char * argv[]) {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif

    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    ll S;
    
    cin >> S;
    
    ll left = 1;
    ll right = S;
    ll result = 0;
    while(left <= right){
        
        ll middle = (left + right) / 2;
        
        ll sum = middle * (middle + 1)/2;
        
        
        
        if (S - sum < 0){
            right = middle - 1;
        }
        else if(S - sum <= middle){
            result = middle;
            break;
        }
        else{
            left = middle + 1;
        }
        
    }
    cout << result;
    
    
    
    
    return 0;
}

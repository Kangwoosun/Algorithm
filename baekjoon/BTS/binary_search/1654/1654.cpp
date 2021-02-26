#include <iostream>
#include <string>
#include <climits>
using namespace std;

#define LOCAL
typedef unsigned long long ull;

ull lan[10001];

int K, N;
ull lan_max = 0;
void get_lan(ull start, ull end){
  
    if (start > end)
        return;
    
    ull middle = (start+end) / 2;
    int count = 0;
    
    for (int i =0; i<K; ++i){
        count += (lan[i]/middle);
    }
    
    if (count >= N){
        if(lan_max < middle)
            lan_max = middle;
        get_lan(middle+1, end);
    }
        
    else{
        get_lan(start, middle-1);
    }
    
    return;
}


int main(int argc, const char * argv[]) {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> K >> N;

    for(int i =0; i<K; ++i){
        cin >> lan[i];
    }
    
    get_lan(1, INT_MAX);
    
    cout << lan_max;
    
    return 0;
}

#include <iostream>
using namespace std;

int arr[1002];
int l[1002];
int r[1002];

int dp(int n){
    int result = 0;
    
    l[1] = 1;
    
    for(int i = 1; i<=n; ++i){
        int min = 0;
        for(int j = 0; j<i; ++j){
            if(arr[i] > arr[j])
                if(min < l[j])
                    min = l[j];
            
        }
        l[i] = min + 1;
    }
    
    r[n] = 1;
    for(int i = n; i>=1; --i){
        int min = 0;
        for(int j= n+1; j>i; --j){
            if(arr[i] > arr[j])
                if(min < r[j])
                    min = r[j];
        }
        r[i] = min + 1;
        
        cout << i << ' ' << l[i] << ' ' << r[i] << endl;
        
        result = max(result, r[i] + l[i]-1);
    }

    return result;
}

int main(){
    int N, input;
    cin >> N;
    for(int i = 1; i<=N; ++i){
        cin >> input;
        arr[i] = input;
    }
    cout << dp(N);
}
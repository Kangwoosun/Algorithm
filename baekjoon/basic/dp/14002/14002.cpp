#include <iostream>
#include <vector>
using namespace std;


int arr[1001];
int d[1001];
vector<int> v[1001];

void dp(int n){
    int result_index = 0;
    
    d[1] = 1;
    
    for(int i=1; i<=n;++i){
        int min = 0;
        int index = 0;
        for(int j = 0; j<i; ++j){
            
            if(arr[i] > arr[j])
                if(min < d[j]){
                    min = d[j];
                    index = j;
                }
        }
        v[i].assign(v[index].begin(), v[index].end());
        v[i].push_back(arr[i]);
        d[i] = min+1;
        if(d[result_index] < d[i]){
            result_index = i;
        }
    }
    
    cout << d[result_index] << '\n';
    
    for (auto e:v[result_index]){
        cout << e << ' '; 
    }
    return;
    
}


int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, input;
    
    cin >> N;
    
    for(int i =1; i<=N; ++i){
        cin >> input;
        arr[i] = input;
    }
    
    dp(N);
    return 0;
}
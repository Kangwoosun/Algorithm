#include <iostream>
using namespace std;


bool visit[41];
int arr[41][2];

void fibonacci(int n) {
	if (visit[n]){
		return;
	}

    if (n == 0) {
    	return;
    
    } else if (n == 1) {
        return;
    } else {
    	fibonacci(n-1);
    	fibonacci(n-2);
    	arr[n][0] += arr[n-1][0] + arr[n-2][0];
    	arr[n][1] += arr[n-1][1] + arr[n-2][1];
    	visit[n-1] = true;
    	visit[n-2] = true;
    }
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	arr[0][0] = 1;
	arr[0][1] = 0;

	arr[1][0] = 0;
	arr[1][1] = 1;

	int T,N;
	cin >> T;

	for(int i =0; i<T; ++i){
		cin >> N;

		fibonacci(N);

		cout << arr[N][0] << " " << arr[N][1] << '\n';
		
		visit[N] = true;

	}

	return 0;
}
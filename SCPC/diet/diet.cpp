/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <algorithm>
using namespace std;

int A[200001];
int B[200001];
int Answer;

int max(int a, int b){return (a>b?a:b);}

int get_cal(int N, int K){
    int result = 0;
    sort(A, A+N);
    sort(B, B+N);
    
    for(int i =0; i<K; ++i){
        result = max(result, A[i] + B[K-i-1]);
    }
    
    return result;
}

int main(int argc, char** argv)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; ++test_case)
	{

		Answer = 0;
		
		int N, K;
		
		cin >> N >> K;
		
		for(int i =0; i<N; ++i){
		    cin >> A[i];
		}
		for(int i = 0; i<N; ++i){
		    cin >> B[i];
		}
		Answer = get_cal(N, K);
		
		
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
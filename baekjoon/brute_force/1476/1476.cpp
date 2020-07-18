#include <iostream>
using namespace std;

int main(){
    
    
    int E, S , M, sum;
    
    cin >> E >> S >> M;
    
    /*  x = a1n1s1 + a2n2s2 + a3n3s3, nksk ≡ 1 (mod m)
     *
     *  x ≡ E (mod 15), n1s1 ≡ 28*19*s1 ≡ 1 (mod 15), 7s1 ≡ 1 (mod 15) => 7s1 - 15k1 = 1, s1 = 103±105k
     *  x ≡ S (mod 28), n2s2 ≡ 15*19*s2 ≡ 1 (mod 28), 5s2 ≡ 1 (mod 28) => 5s2 - 28k2 = 1, s2 = 129±140k
     *  x ≡ M (mod 19), n3s3 ≡ 15*28*s3 ≡ 1 (mod 19), 2s3 ≡ 1 (mod 19) => 2s3 - 19k3 = 1, s3 = 10±38k
     *    
     *  
     *  x = E*532*103 + S*285*129 + M*10*420 (mod 7980)
     *  x = E*6916 + S*4845 + M*4200 (mod 7980)
     *
     *
     *
     *
     */
    
    sum = (E*6916 + S*4845 + M*4200)%7980;
    
    if (sum == 0)
        sum = 7980;
    cout << sum;
    
    
    return 0;
}
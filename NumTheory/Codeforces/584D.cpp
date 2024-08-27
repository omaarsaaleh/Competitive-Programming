#include<iostream>
#include <cmath>
#include<vector>
#include<algorithm>

using namespace std;
#define ll long long 


bool is_prime(int n){
    if (n < 2) return false;
    
    for(int i=2; i*i <= n ; i++){ 
        if(!(n%i)) return false ;
    }
    return true ;
}

int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);

    int n ; cin >> n ;
    if(is_prime(n)) cout << "1\n" << n << '\n' ;
    else{
        cout << "3\n3 ";
        n-=3 ;
        for(int i=2 ; i<=n ; i++){
            if(is_prime(i) && is_prime(n-i)){
                cout << i << ' ' << n-i  ;
                return 0 ;
            }
        }
    }
    

    return 0 ;
}

/*]

Goldbach's conjecture
any even number >2 can be expressed as the sum of two prime numbers
proven till 4 x 1e18


*/
#include<iostream>
#include <cmath>
#include<vector>
#include<algorithm>

using namespace std;
#define ll long long 

void PrimeFactorization(ll n){ //o(sqrt(n)logn)
    int power ;
    for (ll i = 2; i * i <= n; i++) {
        power = 0;
        while (!(n%i)) { 
            power++ ;
            n /= i; 
        }
        if (power) cout << i << '^' << power << ' ' ;
    }
    
    if (n != 1) cout << n << '^' << 1 << '\n' ;
    
}


int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);

    ll n ; 
    while(cin >> n && n){
        PrimeFactorization(n) ;
    }
    
    return 0 ;
}
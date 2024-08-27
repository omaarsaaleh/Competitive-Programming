#include<iostream>
#include <cmath>
#include<vector>
#include<algorithm>

using namespace std;
#define ll long long 

const int MOD = 1e9+7 ;

ll power(ll num , int pow){ // log(pow)
    ll ans = 1 ;
    while (pow) {
        if (pow & 1) 
            ans = (ans * num) % MOD;
        
        num = (num * num) % MOD;
        pow >>= 1; // /= 2
    }
    return ans ;
}


int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);

    int t ; cin >> t ;
    cout << power(2,t) ;
    
    
    return 0 ;
}
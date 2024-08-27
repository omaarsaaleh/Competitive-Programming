#include<iostream>
#include <cmath>
#include<vector>
#include<algorithm>

using namespace std;
#define ll long long 

ll GreatestPrimeFactor(ll n){
    ll ans;
    for (ll i = 2; i * i <= n; ++i) {
        bool power = 0;
        while (!(n%i)) { 
            power = 1 ;
            n /= i; 
        }
        if (power) ans = i;
    }
    return ((n != 1)? n : ans) ;
}


int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);

    int t ; cin >> t ;
    while(t--){
        ll n ; cin >> n ;
        cout << GreatestPrimeFactor(n) << '\n' ; 
    }
    
    return 0 ;
}

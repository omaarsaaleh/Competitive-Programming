#include<iostream>
#include <cmath>
#include<vector>
#include<map>

using namespace std;
#define ll long long 

const int MOD = 1e9+7;

vector<pair<int, int>> PrimeFactorization(int n){
     
    vector<pair<int, int>> factors;
    for (int i = 2; i * i <= n; ++i) {
        int power = 0;
        while (!(n%i)) { 
            power++ ;
            n /= i; 
        }
        if (power > 0) factors.emplace_back(i, power);
    }
    
    if (n != 1) factors.emplace_back(n, 1);
    
    return factors;
}

int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);

    int n ; cin >> n ;
    map<int,int> mp ;
    for(int i=2 ; i<=n ; i++){
        vector<pair<int,int>> v = PrimeFactorization(i) ;
        for(auto &e : v){
            mp[e.first] += e.second ;
        }
    }

    ll ans = 1 ;
    for(auto &e : mp) ans = (ans*(e.second+1)) % MOD;  ; 
    cout << ans ; 
    
    
    return 0 ;
}

/*
3! = 2*3 = 6
Prime factors of 2 and 3 : 2 * 3

Divisors : 1 2 3 6
1 -> 2^0 * 3^0
2 -> 2^1 * 3^0
3 -> 2^0 * 3^1
6 -> 2^1 * 3^1

so it's *= (exponents+1)

*/

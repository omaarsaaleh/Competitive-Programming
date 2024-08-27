#include<iostream>
#include <cmath>
#include<vector>
#include<map>
#include<numeric>

using namespace std;
#define ll long long 

map<int, int> PrimeFactorization(int n){ 
     
    map<int, int> factors;
    for (int i = 2; i * i <= n; i++) {
        int power = 0;
        while (!(n%i)) { 
            power++ ;
            n /= i;
        }
        if (power > 0) {
            factors[i] = power;
        }
    }
    
    if (n != 1) factors[n] = 1;

    
    return factors;
}

ll lcm(int a, int b){ //O(log(min(a,b)){ 
    return (a*b / gcd(a, b)); 
} 

int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);

    int t ; cin >> t ;
    while(t--){
        int n ; cin >> n ;
        ll ans = 1 ;
        for(int i=2 ; i<=n ; i++){
            ans = lcm(ans,i) ;
        }
        cout << ans << '\n' ;

    }
    return 0 ;
}


/*

map<int,int> ansfac ;
        for(int i=2 ; i<=n ; i++){
            map<int,int> mp = PrimeFactorization(i) ;
            for(const auto &e : mp ){
                ansfac[e.first]=max(ansfac[e.first],e.second);
            }
        }
        ll ans = 1 ;
        for(const auto &e : ansfac){
            ans *= pow(e.first,e.second) ;
        }
        cout << ans << '\n' ;






















2^3 * 3^2 * 5 * 7
2      3
4      9
8






*/
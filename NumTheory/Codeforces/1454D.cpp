#include<iostream>
#include <cmath>
#include<vector>
#include<algorithm>

using namespace std;
#define ll long long 

vector<pair<int, int>> PrimeFactorization(ll n , int &ans , ll &base){
    vector<pair<int, int>> factors;
    for (ll i = 2; i * i <= n; ++i) {
        int power = 0;
        while (!(n%i)) { 
            power++ ;
            n /= i; 
        }
        //cout << i << ' ' << power << '\n' ;
        if (power > 0) factors.emplace_back(i, power);
        if(power>ans){ans=power; base=i;}
    }
    if (n != 1) {
        factors.emplace_back(n, 1);
        if(ans==0){ans=1; base=n;}
    }
    
    
    return factors;
}

int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);

    int t ; cin >> t ;
    while(t--){
        ll n ; cin >> n ;
        ll base ; int ans = 0 ;
        vector<pair<int,int>> v = PrimeFactorization(n,ans,base) ;
        cout << ans << '\n' ;
        
        ll factor = 1 ;
        for(int i=0 ; i<ans-1 ; i++){
            cout << base << ' ' ;
            factor *= base ;
        }
    
        cout << n/factor << '\n' ;
    }
    
    return 0 ;
}

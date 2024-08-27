#include<iostream>
#include <cmath>
#include<vector>
#include<algorithm>

using namespace std;
#define ll long long 

vector<pair<int, int>> PrimeFactorization(int n , int &numfactors){
     
    vector<pair<int, int>> factors;
    for (int i = 2; i * i <= n; ++i) {
        int power = 0;
        while (!(n%i)) { 
            power++ ;
            n /= i; 
        }
        if (power > 0) {factors.emplace_back(i, power); numfactors+=power;}
    }
    
    if (n != 1) {factors.emplace_back(n, 1); numfactors++;}
    
    return factors;
}


int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);

    int n,k ; cin >> n >> k ;
    int numfactors = 0;
    vector<pair<int, int>> v = PrimeFactorization(n,numfactors) ;
    if(k>numfactors) cout << "-1" ;
    else{
        int j = 0 ;
        int rest = 1 ;
        for(int i=0 ; i<k-1 ; i++){
            cout << v[j].first << ' ' ;
            rest *= v[j].first;
            v[j].second--;
            if(!v[j].second) j++;
        }
        cout << n/rest << '\n' ;
    }

    
    
    return 0 ;
}

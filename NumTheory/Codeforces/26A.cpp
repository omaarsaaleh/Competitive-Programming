#include<iostream>
#include <cmath>
#include<vector>
#include<algorithm>
#include <set>
#include <chrono>

using namespace std;
#define ll long long 


bool AlmostPrime(int n){
    int ogvalue = n ;
    bool one = 0 , two = 0;
    for (int i = 2; i * i <= n; ++i) {
        if(!(n%i)){
            if(one && !two) two = true ;
            else if(one && two ) return false ;
            if(!one) one = 1;
            
            while (!(n%i)) { // i is the smallest prime factor of n            
                n /= i; // remove i from n and repeat the process
            }
        }
    }
    return (n!=1 && n!=ogvalue && one && !two) || (one && two && n==1)  ;
}


int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);

    int n ; cin >> n ;
    int ans = 0;
    for(int i=6 ; i<=n ; i++){
        if(AlmostPrime(i)){
            ans++;
        }
    }
    cout <<  ans ;
    return 0 ;
}


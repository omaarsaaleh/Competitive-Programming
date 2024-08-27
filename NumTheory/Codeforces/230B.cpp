#include<iostream>
#include <cmath>
#include<vector>
#include<algorithm>

using namespace std;
#define ll long long 

void countDivisors(ll N , vector<int> &d) { // 
    for (ll i = 1; i <= N; ++i) {
        for (ll j = i; j <= N; j += i) {
            d[j]++;
        }
    }
}

int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);

    int n ; cin >> n ;
    vector<ll> v(n); ll maxval = -5 ;
    for(auto &e : v){
        cin >> e ;
        maxval = max(maxval,e);
    }
    
    vector<int> d(1e6+1);
    countDivisors(1e6+1,d);

    for(auto &e : v){
        ll u = sqrt(e) ;
        cout << ((u*u==e &&d[u]==2 )? "YES\n" : "NO\n") ;
    }
    
    
    return 0 ;
}

// it should be a square number a
/*
it will be divisable by 
1 (x) and n
so it should be x*x 
and x is a prime number
in order to not have any other divisor rather than x

1 2 4
1 3 9
1 5 25

4 is not a prime number so 2 is a divisor also
1 4 16





*/
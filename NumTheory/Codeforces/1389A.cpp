#include<iostream>
#include <cmath>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;
#define ll long long 


ll lcm(ll a, ll b){ //O(log(min(a,b)){ 
    return (a*b / gcd(a, b)); 
} 

int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    
    int t ; cin >> t ;
    while(t--){
        int l,r ; cin >> l >> r ;
        if(2*l>r) cout << "-1 -1\n" ;
        else cout << l << ' ' << 2*l << '\n' ;

    }
    
    return 0 ;
}

/*
to satisfy a <= lcm(a,b) <= b
b should be n*a so where n is an integer >= 1
so the lcm would be equal to b
so the least numbers that could satisfy this constraint
would be l and 2*l if acuatly falls in the range


if we have (3,5)=15 within the range 3 -> 15
we also have (3,6)=6 and (5,10)=10 

*/
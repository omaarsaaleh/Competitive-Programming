#include<iostream>
#include <cmath>
#include<vector>
#include<algorithm>

using namespace std;
#define ll long long 

int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);

    int t ; cin >> t ; 
    while(t--){
        int a,b ; cin >> a >> b ;
        int m = a*b ;

        // gcd*lcm = x*Y
        
        if(!(b%a))
            cout << a << ' ' << b << '\n';
        // since b is a multiple of x and y
        // and a is a divisor of x and and y
        // so b must be divisable by a 
        else 
            cout << "-1\n" ;
    }
    
    return 0 ;
}


/*

a b
gcd(x,y)=a
lcm(x,y)=b
where x is minimized

 b*a 
---- = y
  x
where x>= gcd x+=gcd

x * y
gcd = 8
lcm = 12

x,y >= 8

x*y = 12*8

3 * 4
gcd = 1
lcm = 12


gcd = 6
lcm = 8



*/
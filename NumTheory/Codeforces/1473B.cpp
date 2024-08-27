#include<iostream>
#include <cmath>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;
#define ll long long 

/*

times & power == if(power is part of times)
101
001 1
100 4

times = 5
pow = 1
res = ab
sub = abab

pow = 2
res = ab
sub = abababab

power = 4
res = 5*ab
sub = 8*ab 

pow = 8

*/

string multiply(string substring, int times) {
    string result = "";
    int power = 1;
    
    while (power <= times) {
        if (times & power) {
            result += substring;
        }
        substring += substring; 
        power <<= 1; // *= 2
    }
    
    return result;
}



int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);

    int t ; cin >> t ;
    while(t--){
        string a,b ; cin >> a >> b ;
        
        string pattern = a.substr(0,gcd(a.size(),b.size()));
        
        int as = a.size()/pattern.size() ;
        int bs = b.size()/pattern.size() ;
        if(multiply(pattern,as)==a
        && multiply(pattern,bs)==b){
            cout << multiply(pattern,as*bs/gcd(as,bs)) << '\n';
        }
        else cout << "-1\n" ;
    }
    
    return 0 ;
}

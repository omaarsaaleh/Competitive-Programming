#include<iostream>
#include <cmath>
#include<vector>
#include<algorithm>
#include<numeric>
#include<map>

using namespace std;
#define ll long long 


map<int, int> PrimeFactorization(int n){ //o(sqrt(n)logn)
     
    map<int, int> factors;
    for (int i = 2; i * i <= n; i++) {
        int power = 0;
        while (!(n%i)) { 
            power++ ;
            n /= i; 
        }
        if (power > 0) {factors[i] = power;}
    }
        if (n != 1) {factors[n] = 1; }
    
    return factors;
}

int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);

    int a,b; cin >> a >> b;
    int af[] = {0,0,0};
    int bf[] = {0,0,0};
    
    int j=0 ;
    for(int i:{2,3,5}){
        while(!(a%i)){
            af[j]++; a/=i;
        }
        j++;
    }
    
    j=0 ;
    for(int i:{2,3,5}){
        while(!(b%i)){
            bf[j]++; b/=i;
        }
        j++;
    }
    
    if (a!=b) {cout << -1; return 0;}
    
    int ans = 0 ;
    for(int i=0 ; i<3 ; i++) ans+=abs(af[i]-bf[i]);
    cout << ans ;
    
    return 0 ;
}

/*
better solution just /2 all and count it
                     /3 all and count it
                     /5 all and count it
if(a!=b) cout << -1
else count abs(x2divions-y2divisions) and so on

    

int a,b ; cin >> a >> b ;
    map<int, int> af = PrimeFactorization(a);
    map<int, int> bf = PrimeFactorization(b);

    int ans = 0 ;
    for(int i : {2,3,5}){
        if(af[i]>bf[i]){
            ans+=af[i]-bf[i];
            af[i]=bf[i] ;
            
        }
        else{
            ans+= bf[i]-af[i];
            bf[i]=af[i] ;
            
        }
    }    
    
    if(bf.size()!=af.size()){cout << -1 ; return 0;}    
    for(const auto &e : af){
        if(bf[e.first]!=e.second){cout << "-1" ; return 0 ;}
    }
    
    cout << ans ;
    
    return 0 ;




2,3,5


15 20
15 = 3*5
20 = 2*2*5

2 15 10
2 15 5
3 5 5

14 8
2 * 7
2 * 2 * 2
*/
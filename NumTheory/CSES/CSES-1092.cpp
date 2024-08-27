#include<iostream>
#include <cmath>
#include<vector>
#include<algorithm>

using namespace std;
#define ll long long 


int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);

    ll t ; cin >> t ;
    if((t*(t+1)/2)%2) cout << "NO\n" ;
    else{
        cout << "YES\n" ;
        vector<int> v1 ; ll s1 = t ; v1.push_back(t) ;
        vector<int> v2 ; ll s2 = 0 ;
        for(int i=t-1 ; i>0 ; i--){
            if(s1>s2) {
                s2 += i ; v2.push_back(i);
                if(s1==s2 && (i-1)) {
                    s1+= --i ; v1.push_back(i);
                }
            }
            else if(s2>s1){
                s1+= i ; v1.push_back(i) ;
                if(s1==s2 && (i-1)){
                    s2+= --i ; v2.push_back(i);
                }
            }
        }
        cout << v1.size() << '\n' ;
        for(auto &e : v1 ) cout << e << ' ' ;
        cout << '\n' ;
        cout << v2.size() << '\n' ;
        for(auto &e : v2 ) cout << e << ' ' ;
    }
    
    
    
    return 0 ;
}

/*

1,2,3,4,5,6,7

2 x
3 -> 1,2 3
4 -> 1,4 2,3
5 -> x
6 -> x
7 -> 1,2,4,7 3,5,6

*/
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
        int n ; cin >> n ;
        vector<int> v(n) ;
        for(auto &e:v) cin >> e ;
        
        bool ok = 0 ;
        for(int i=0 ; i<n ; i++){
            ok = 0 ;
            for(int j=i+2 ; j>=2 ; j--){
                if( v[i]%(j) ){
                    ok = 1 ;
                    break ;
                }
            }
            if(!ok) break ;
        }
        cout << ((ok)? "YES\n" : "NO\n") ;

    }
    
    return 0 ;
}

/*

3 4 5 2 1
1 1 1 1 1


*/
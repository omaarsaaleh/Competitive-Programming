#include<iostream>
#include <cmath>
#include<vector>
#include<algorithm>
#include<numeric>

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
        sort(v.begin(),v.end(),greater<int>());
        
        cout << v[0] << ' ';
        int g = v[0] ;
        v[0]=0 ;
        int temp = INT_MIN ;
        int idx ;
        for(int i=1 ; i<n ; i++){
            for(int j=1 ; j<n ; j++){
                if(v[j]){
                    int a = gcd(g,v[j]) ;
                    if(temp < a){
                        temp = a ;
                        idx = j ;
                    }
                }
            }
            if(temp == 1 ){
                for(auto & e : v){
                    if(e) cout << e << ' ' ; 
                }
                
                break ;
            }
            else{
                g = temp ;
                temp = INT_MIN ;
                cout << v[idx] << ' ' ;
                v[idx] = 0 ;
            }
        }
        cout << '\n' ;
    }
    
    return 0 ;
}

/*

2 5

5 2
gcd(5,5) , gcd(5,2)
5 1

2 4 8 16 17
17 
8 4 2 1 

17 2 4 8 16 
17 1 1 1 1 

1 8 2 3
8 2 1 3
8 2 1 1 

// biggest 
// step two try to preserve non 1 gcds
18 
9 6 12 16
3 6 6  2  




*/
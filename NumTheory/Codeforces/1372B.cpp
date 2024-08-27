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
        bool done = 0 ;
        for(int i=2 ; i*i<=n ; i++){
            if(!(n%i)){
                cout << n/i << ' ' << n - n/i << '\n';
                done = 1 ; break ;
            }
        }

        if(!done) cout << "1 " << n-1 << '\n' ;
    }

    
    return 0 ;
}
/*


if even n/2,n/2 would be = n/2
any other solution would be at >= n/2+1

if even n/2 n/2
if /3 n/3 2n/3
if /5 n/5 4n/5 and so on

*/
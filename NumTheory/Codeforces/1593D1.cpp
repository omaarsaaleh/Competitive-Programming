#include<iostream>
#include <cmath>
#include<vector>
#include<algorithm>
#include<numeric>
#include<set>

using namespace std;
#define ll long long 


int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);

    int t ; cin >> t ;
    while(t--){
        int n ; cin >> n ;
        
        set<int> st ;
        int x ;
        while(n--){
            cin >> x ;
            st.insert(x);
        }
        x = *st.begin();
        int ans = 0 ;
        for(auto i=++st.begin() ; i!=st.end() ; i++){
            ans = gcd(ans,*i-x) ;
        }
        // ans = 0 means all numbers of the array are the same
        cout << ((ans)? ans : -1) << '\n';
    }
    
    return 0 ;
}
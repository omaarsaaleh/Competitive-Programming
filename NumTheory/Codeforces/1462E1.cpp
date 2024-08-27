#include<iostream>
#include <cmath>
#include<vector>
#include<algorithm>

using namespace std;
#define ll long long


unsigned ll nCr(int n, int r) {
    if(r>n) return 0 ;
    if (r > n - r) {
        r = n - r; 
    }

    long long result = 1;
    for (int i = 0; i < r; ++i) {
        result *= (n - i);
        result /= (i + 1);
    }
    return result;
}


int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    
    int t ; cin >> t ;
    int k = 2 , m = 3 ;
    while(t--){
        int n; cin >> n ;
        vector<int> v(n) ;
        for(auto &e:v) cin >> e ;
        sort(v.begin(),v.end());
 
        int i=0,j=0 ;
        unsigned ll ans = 0 ;
        bool left = 0 ;
        int prevEnd ;
        while(j<n && i<n){
            if(v[j]-v[i]<=k){
                j++;
                left = 1 ;
            }
            else{
                if(j-i>=m){
                    ans += nCr(j-i,m)-((ans)?nCr(prevEnd-i,m):0);
                    left = 0 ;
                }
                prevEnd = j ;
                while(i<n && v[j]-v[i]>k)i++;
            }
        }
        if(left && j-i>=m){
            ans += nCr(j-i,m)-((ans)?nCr(prevEnd-i,m):0);
        }
 
        cout << ans << '\n' ;
    }

    
    return 0 ;
}


/*

1 2 3 3 4 4 4 5
s(s-1)/2

3*2/2 = 3


1 1 1 1 2 3 3 3 4
0 1 2 3 4 5 6 7 8 
8c3 + 5c3 - 4c3
7C2+6c2+4c2+3C2+2C2+4C2+3C2+2C2






*/
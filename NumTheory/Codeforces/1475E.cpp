#include<iostream>
#include <cmath>
#include<vector>
#include<algorithm>
#include<numeric>
#include<map>

using namespace std;
#define ll long long 

const int MOD = 1e9+7;

int nCr(int n, int r) {
    if (r > n - r)
        r = n - r;

    vector<int> dp(r + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = min(i, r); j > 0; --j)
            dp[j] = (dp[j] + dp[j - 1]) % MOD;
    }

    return dp[r];
}




int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);

    int t; cin >> t ;
    while(t--){
        int  n,k ; cin >> n >> k ;
        vector<int>v(n) ;
        for(auto &e : v) cin >> e ;
        sort(v.begin(),v.end(),greater<int>()) ;
        if(k==v.size() || v[k-1]!=v[k]){
            cout << "1\n" ;
            continue;
        }
        
        int ans = count(v.begin(), v.end(), v[k-1]);
        int start = 0;
        while(v[start]!=v[k-1]) start++;
        cout << nCr(ans,k-start) << '\n' ; 
    }

    return 0 ;
}


/*
3 2 1. 1, (3)
k = 3

3 3 2 2 1 1 1 (4)
3 3 2 2

3 3 2 2 1 1 1 (5)
0 1 2 3 4 5 
3 3 2 2 1. 
3 3 2 2 1,
3 3 2 2 1/ 

2 1 1 1
0 1  

*/
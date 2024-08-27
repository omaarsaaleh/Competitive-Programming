#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long

 
const ll N = 5e5 + 7, mod = 1e9 + 7;
 
ll POW(ll a, ll b, ll mod){
    a %= mod;
    ll r = 1;
    for(ll i = b; i > 0; i >>= 1)
    {
        if(i & 1)
            r = (r * a) % mod;
        a = (a * a) % mod;
    }
    return r;
}
 
ll f[N];
 
 
ll nCr(ll n, ll r)
{
    if(n < r)
        return 0;
    return f[n] * POW(f[n - r] * f[r], mod - 2, mod) % mod;
}

 
 
int main()
{
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    f[0] = 1;
    for(ll  i = 1; i < N; i++){
        f[i] = (f[i - 1] * i) % mod;
    }
 
    int t ; cin >> t ;
    while(t--){
        int n,m,k; cin >> n >> m >> k ;
        
        vector<int> v(n);
        for(auto &e : v) cin >> e ;
        sort(v.begin(),v.end());
        
        ll ans=0;
        for(int i=0; i<n; i++){
            int sz=upper_bound(v.begin(),v.end(),v[i]+k)-v.begin()-i;
            if(sz>=1){
                ans = (ans+nCr(sz-1,m-1))%mod ;
            }
 
        }
        cout<<ans<<'\n';
    }

    return 0 ;
}

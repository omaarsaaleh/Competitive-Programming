#include<iostream>
#include <cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<iomanip>
#include <string>
#include <map>
#include<queue>
#include<numeric>
#include <sstream>
 
 
using namespace std;
#define ll long long 
#define all(x) x.begin(), x.end()
#define for1(n) for (int i = 0; i<n; i++)
#define for2(n) for (int j = 0; j<n; j++)
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define eache auto &e
 
template<class t>
void print(const t a) {cout << a << '\n';}
template<class t>
void print(const vector<t>&v){for(t e:v){cout<<e<<' ';}cout<<'\n';}
template<class t>
void print(const vector<vector<t>>&v) {for(vector<t> e:v)print(e);}

// Codeforces 1139C
// Edgy Trees

const int MOD = 1e9+7 ;

ll power(ll num , int pow){ // log(pow)
    ll ans = 1 ;
    while (pow) {
        if (pow&1)
            ans = (ans * num) % MOD;
        
        num = (num * num) % MOD;
        pow >>= 1; // /= 2
    }
    return ans ;
}


struct DSU{
    vector<int> parent, sz ;
    DSU(int n) {
        parent = sz = vector<int> (n + 1, 0);
		for(int i = 1; i <= n; i++)
			parent[i] = i, sz[i] = 1;
    }
    
    int Find(int x){
        if ( parent[x] == x) return x;
        return parent[x] = Find( parent[x] );
    }
    
    void Union(int u, int v){
        int par1 = Find(u), par2 = Find(v);	
        if(par1 == par2) return;

        if(sz[par1] > sz[par2]) 
            swap(par1, par2);
        sz[par2] += sz[par1];
        sz[par1] = 0;
        parent[par1] = par2;
    }

    vector<int> get_comp_sizes(){
        int n = parent.size() - 1 ;
        map<int,int> comp_sizes ;
        for(int i=1 ; i<=n ; i++){
            comp_sizes[parent[Find(i)] ]++ ;
        }
        vector<int> values;
        for (const auto& pair : comp_sizes) 
            if(pair.second>1) values.push_back(pair.second);
        
        return values ;
        
    }
    
    bool is_connected(int u, int v)  { return this->Find(u)==this->Find(v) ;}

};


int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    
    int n,k ; cin >> n >> k ;
    int m = n-1 ;
    DSU d(n) ;
    for1(m){
        int a,b,w; cin >> a >> b >> w ;
        if(w==0)
            d.Union(a,b) ;
    }

    auto v = d.get_comp_sizes() ;

    ll ans = power(n,k) - n;

    for(int a : v){
        ll f = (power(a,k) - a) % MOD ;
        ans = (ans - f + MOD) % MOD ;
    }

    cout << ans ;

    return 0 ;
}




/*
c^p

upper limit n^k - k

7^3 - 4^3 + 4 - 7 - 2^3 + 2


n^k - k

for every connect pink component
- compsize^k + compsize





*/
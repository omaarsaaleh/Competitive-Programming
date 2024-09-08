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
// Harmonious Graph

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
    vector<pii> min_max ;
    DSU(int n) {
        parent = sz = vector<int> (n + 1, 0);
        min_max = vector<pii>(n+1) ;
		for(int i = 1; i <= n; i++)
			parent[i] = i, sz[i] = 1, min_max[i]={i,i};
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
        min_max[par2] = {min(min_max[par1].first,min_max[par2].first),
        max(min_max[par1].second,min_max[par2].second)} ;
        min_max[par1] = {0,0} ;
        sz[par1] = 0;
        parent[par1] = par2;
    }

    int solve(){
        int n = sz.size() ; 
        vector<pii> v ;

        int ans = 0 ;
        for(int k=0 ; k<2; k++){
            for(int i=1; i<n ; i++){
                if(sz[i]>1){
                    int mx = min_max[i].second ;
                    for(int j=min_max[i].first+1; j<mx ; j++){
                        if(this->is_connected(mx,j)==false){
                            ans++ ;
                            this->Union(mx,j);
                        }
                    }
                }
                    
            }
        }

        return ans ;

    }

    bool is_connected(int u, int v)  { return this->Find(u)==this->Find(v) ;}

};

/*


*/
int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    
    int n,m ; cin >> n >> m ;
    DSU d(n) ;
    
    for1(m){
        int a,b; cin >> a >> b  ;
        d.Union(a,b) ;
    }

    cout << d.solve() ;

    return 0 ;
}
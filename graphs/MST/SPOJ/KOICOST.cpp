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

// SOPJ KOICOST

const int MOD = 1e9 ;
 

template<class t>
void print(const t a) {cout << a << '\n';}
template<class t>
void print(const vector<t>&v){for(t e:v){cout<<e<<' ';}cout<<'\n';}
template<class t>
void print(const vector<vector<t>>&v) {for(vector<t> e:v)print(e);}


struct DSU{
    vector<int> parent ;
    vector<int> sz ;
    DSU(int n) {
        parent.resize(n+1);
        sz.resize(n+1, 1);
        for(int i = 1; i <= n; i++)
            parent[i] = i;
    }
    
    int Find(int x){
        if ( parent[x] == x) return x;
        return parent[x] = Find( parent[x] );
    }

    bool is_connected(  int u, int v){
        return Find(u) == Find(v) ;
    }
    
    bool Union(int u, int v){
        int par1 = Find(u), par2 = Find(v);	
        if(par1 == par2){
            return false ;
        }

        if(sz[par1] > sz[par2]) 
            swap(par1, par2);
        sz[par2] += sz[par1];
        sz[par1] = 0;
        parent[par1] = par2;
        return true ;
    }

    ll get_comp_size(int u){
        return sz[Find(u)] ;
    }


};

struct Edge {
    int u, v, weight;
    Edge(int a, int b, int c) : u(a),v(b),weight(c){}
    bool operator<(Edge const& other) {
        return weight > other.weight;
    }
    bool operator>(Edge const& other) {
        return weight < other.weight;
    }
};

ll MST(int &n, vector<Edge> &edges){
    
    DSU d(n) ;    

    sort(edges.begin(), edges.end());
    ll cost = 0;
    for(Edge e : edges) cost+= e.weight ;
    ll ans = 0 ;
    for (Edge e : edges) {
        if (d.is_connected(e.u,e.v)==false) {
            ll product = (d.get_comp_size(e.v) * d.get_comp_size(e.u)) % MOD;     
            ll term = (product * (cost % MOD)) % MOD;
            ans = (ans + term) % MOD; 

            d.Union(e.u, e.v);
        }
        cost -= e.weight ;
        
    }
    return ans ;
}


int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);

    int n,m ; cin >> n >> m;
    vector<Edge> edges ;
    for1(m){
        int a,b,w ; cin >> a >> b >> w ;
        edges.push_back(Edge(a,b,w)) ;
    }
    cout << MST(n,edges) << '\n';

    return 0 ;
}




/*

*/

/*

45
30

comp1 x comp2 * current

14




*/
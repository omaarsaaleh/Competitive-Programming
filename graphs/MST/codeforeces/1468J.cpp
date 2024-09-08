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
#define for1(n) for (int i = 1; i<=n; i++)
#define for2(n) for (int j = 1; j<=n; j++)
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

// Codeforces 1468J
// Road Reform

struct DSU{
    vector<int> parent, sz ;
    DSU(int n){
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

    
    bool is_connected(int u, int v)  { return this->Find(u)==this->Find(v) ;}

};

struct Edge {
    int u, v, weight;
    Edge(int a, int b, int c) : u(a),v(b),weight(c){}
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
    bool operator>(Edge const& other) {
        return weight > other.weight;
    }
};

int k ;

ll MST(int &n, vector<Edge> &edges, bool y){
    
    DSU d(n) ;    
    vector<Edge> result;

    sort(edges.begin(), edges.end());
    int m = edges.size() ;
    ll nearest = INT_MAX ;
    if(y){   
        int idx ;
        for(int i=0 ; i<m ; i++){
            int d = abs(edges[i].weight-k) ;
            if(d<nearest){
                nearest = d ;
                idx = i ;
            }
        }
        d.Union(edges[idx].u,edges[idx].v) ;
    }
    ll ans = 0 ;
    int last_added ;
    for (Edge e : edges) {
        if (d.is_connected(e.u,e.v)==false) {
            if(e.weight>k) ans += e.weight-k ;
            last_added = e.weight; 
            d.Union(e.u, e.v);
        }
    }
    if(last_added<k && !y) ans = k-last_added ;
    return ans+(y? nearest : 0) ;
}

int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    

    int t ; cin >> t ;
    while (t--){
        int n,m; cin >> n >> m >> k ;
        vector<Edge> edges;
        for1(m){
            int a,b,c ; cin >> a >> b >> c ;
            edges.push_back(Edge(a,b,c)) ;
        }
        cout << min(MST(n,edges,0),MST(n,edges,1)) << '\n';
    }
    


    return 0 ;
}

/*
1
5 5 7
1 2 3
2 4 8
1 5 4
5 4 5
4 3 9
*/
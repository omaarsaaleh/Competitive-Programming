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

// Bring Your Own Horse
// https://onlinejudge.org/external/121/12176.pdf
// MST + DFS

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

vector<vector<pii>> MST(int &n, vector<Edge> &edges){
    
    DSU d(n) ; 
    vector<vector<pii>> adj(n+1,vector<pii>());
    sort(edges.begin(), edges.end());
    for (Edge e : edges) {
        if (d.is_connected(e.u,e.v)==false) {
            adj[e.u].push_back({e.v,e.weight});
            adj[e.v].push_back({e.u,e.weight});
            d.Union(e.u, e.v);
        }
    }
    return adj ;
}

int qans=-1 ;
void dfs(int cur, int dest, int prev, int dis, vector<vector<pii>> &adj){
    if(cur==dest) {qans=dis;}
    if(qans!=-1) return;
    for( pii a : adj[cur]){
        if(a.first!=prev){ 
            dis = max(dis,a.second);
            dfs(a.first,dest,cur,dis,adj);
        }
    }
}



int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    string _ ;

    int t ; cin >> t ;
    for (int mm=1 ; mm<=t ; mm++){
        int n,m ; cin >> n  >> m;
        
        vector<Edge> edges ;
        for2(m){
            int a,b,w ; cin >> a >> b >> w ;
            edges.push_back(Edge(a,b,w)) ;
        }
        vector<vector<pii>> adj = MST(n,edges);

        cout << "Case " << mm << '\n';
        int q ; cin >> q ;
        while (q--){
            int a,b ; cin >> a >> b ;
            dfs(a,b,-1,0,adj);
            cout << qans << '\n' ;
            qans = -1 ;
        }
        cout << '\n';

    }
    
    


    return 0 ;
}

/*
1 2 9
2 4 19
5 4 31
2 5 42 x
3 4 51
3 5 66 x
1 3 75 x
3 2 95 x
*/
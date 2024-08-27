
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
#define eache auto &e
 
template<class t>
void print(const t a) {cout << a << '\n';}
template<class t>
void print(const vector<t>&v){for(t e:v){cout<<e<<' ';}cout<<'\n';}
template<class t>
void print(const vector<vector<t>>&v) {for(vector<t> e:v)print(e);}

// Cyclic or not

bool isCyclic_u_helper(int v, int par, vvi &adj, vector<bool> &vis){
    vis[v] = true ;
    bool cyclic = false ;
    for(int neigh : adj[v]){
        if(!vis[neigh])
            cyclic |= isCyclic_u_helper(neigh, v, adj, vis) ;
        else
            if(neigh!= par)
                return true ;
    }
    return cyclic ;
}

bool isCyclic_u(vvi &adj){
    int sz = adj.size() ;
    vector<bool> vis(sz,0);
    for(int i=0 ; i<sz ; i++) 
        if(vis[i]==false && isCyclic_u_helper(i,-1,adj,vis)) return true ;

    return false ;
}

int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    
    int n, e ; cin >> n >> e ;
    vvi adj(n) ;
    for1(e){
        int a,b ; cin >> a >> b ;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << (isCyclic_u(adj)? "NO" : "YES") ;

    return 0 ;
}


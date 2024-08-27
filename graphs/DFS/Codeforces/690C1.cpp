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
#include <fstream>

using namespace std;
#define ll long long 
#define all(x) x.begin(), x.end()
#define for1(n) for (int i = 0; i<n; i++)
#define vi vector<int>
#define vvi vector<vector<int>>
#define eache auto &e


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

bool is_tree(vvi &adj){
    int sz = adj.size() ;
    vector<bool> vis(sz,0);
    
    bool c = isCyclic_u_helper(0,-1,adj,vis)  ;

    if(c) return false ;

    for(bool r : vis) if(r==false) return false;

    return true ;
    
}


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int n,m ; cin >> n >> m ;

    vvi adj(n) ;

    for1(m){
        int a,b ; cin >> a >> b ;
        --a, --b ;
        adj[a].push_back(b) ;
        adj[b].push_back(a) ;

    }

    cout << (is_tree(adj)? "yes" : "no") << '\n' ;

    return 0;
}

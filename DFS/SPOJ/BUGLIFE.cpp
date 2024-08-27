
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

// Bipartite or not

bool isBipartite_helper(int v,  vector<vector<int>>& adj , vector<int> &color){
    bool bip = true ;
    for(int neigh : adj[v]){
        if(color[neigh]==0){
            color[neigh] = (color[v]==1? 2 : 1) ;
            bip &= isBipartite_helper(neigh, adj, color) ;
        }
        else{
            if(color[neigh]==color[v]) return false ;
        }
    }
    return bip ;
}
    
bool isBipartite(vector<vector<int>>& adj) {
    vector<int> color (adj.size(),0) ;
    for(int i=0 ; i<adj.size(); i++){
        if(color[i]==0 && !isBipartite_helper(i,adj,color)) return false ;
    }
    return true ;
}



int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    
    int t ; cin >> t ;
    for1(t){
        int n, e ; cin >> n >> e ;
        vvi adj(n) ;
        for1(e){
            int a,b ; cin >> a >> b ;
            a--,b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        cout << "Scenario #" << i+1 << ":\n" ;
        cout << (isBipartite(adj)? "No suspicious bugs found!" : "Suspicious bugs found!") << '\n' ;
    
    }
    return 0 ;
}


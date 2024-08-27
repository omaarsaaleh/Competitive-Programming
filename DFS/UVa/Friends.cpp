
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

// https://onlinejudge.org/external/106/p10608.pdf
// Count the components

void dfs(int v, vvi &adj , vector<bool>&vis, int &count ){
    vis[v] = true ;
    count++; 
    for(int neigh : adj[v]){
        if(vis[neigh]==false){
            dfs(neigh, adj,vis, count) ;
        }
    }
}

int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    
    int t ; cin >> t ;
    while(t--){
        int n,m ; cin >> n >> m ;

        vvi adj(n) ; 
        for1(m){
            int a,b ; cin >> a >> b ;
            a--,b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<bool> vis(n,false) ;
        int mx = -1 ;
        for1(n){
            int cur = 0 ;
            if(!vis[i]) dfs(i,adj,vis,cur) ;
            mx = max(cur,mx) ;
        }

        cout << mx << '\n' ;
    }

    return 0 ;
}


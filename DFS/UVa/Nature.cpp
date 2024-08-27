
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

// https://onlinejudge.org/external/106/10685.pdf
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
    
    while(true){
        int n,m ; cin >> n >> m ;
        if(n==0) break;
        map<string,int> mp ;  
        for1(n){
            string s ; cin >> s ;
            mp[s] = i ;
        }

        vvi adj(n) ;
        for1(m){
            string a,b ; cin >> a >> b ;
            adj[mp[a]].push_back(mp[b]);
            adj[mp[b]].push_back(mp[a]);
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


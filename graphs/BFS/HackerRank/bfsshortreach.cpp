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
#define vi vector<int>
#define vvi vector<vector<int>>
#define eache auto &e
 

void bfs(int st, vvi &adj, vector<bool> &vis, vector<int> &dis){

    queue< pair<int,int> > q ;
    q.push({st,0}) ;
    vis[st] = true ;

    while (q.empty()==false){
        pair<int,int> v = q.front() ;
        q.pop() ;
        dis[v.first] = v.second ;

        for(int u : adj[v.first]){
            if(vis[u]==false){
                vis[u] = true ;
                q.push({u,v.second+1}) ;
            }
        }
    }
    
}

int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    
    int t ; cin >> t ;
    while(t--){
        int n,e ; cin >> n >> e ;
        vvi adj(n) ;
        for1(e){
            int a,b ; cin >> a >> b ;
            --a, --b ;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        int st ; cin >> st ; st--;
        vector<bool> vis(n,false) ;
        vector<int> dis(n,-1) ;

        bfs(st,adj,vis,dis) ;

        for1(n){
            if(i==st) continue;
            else cout << dis[i]*(dis[i]==-1 ? 1 : 6) << ' ' ;
        }
        cout << '\n' ;
    
    }
    
    

    return 0 ;
}

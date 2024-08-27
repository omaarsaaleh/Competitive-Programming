
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

vector<int> ans ;

void dfs(int v, vvi &adj, vector<bool> &vis){
    
    vis[v] = true; 

    for( int u : adj[v]){
        if(vis[u]==false){
            ans[u] = v;
            dfs(u,adj,vis) ;
        }
    }

}


int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    
    int n,r1,r2 ; cin >> n >> r1 >> r2 ;
    --r1,--r2;
    
    vvi adj(n) ;
    ans.resize(n) ;

    for1(n){
        if(i==r1) continue;
        int a; cin >> a ;
        a--;
        adj[a].push_back(i) ;
        adj[i].push_back(a) ;
    }

    vector<bool> vis(n,false) ;
    dfs(r2,adj,vis);

    for1(n){
        if(i==r2) continue;
        cout << ans[i]+1 << ' ' ;
    }
    cout << '\n' ;
    
    return 0 ;
}

// real[ans[i]]
/*

  2
1   3

 3
   2
     1

*/
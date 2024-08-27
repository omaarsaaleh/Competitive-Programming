
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

// num of comp

void dfs(int v, vvi &adj , vector<bool>&vis ){
    vis[v] = true ;
    for(int neigh : adj[v]){
        if(vis[neigh]==false){
            dfs(neigh, adj,vis) ;
        }
    }
}


int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    
    int n,m ; cin >> n >> m;
    vvi v(n) ;
    for1(m){
        int a,b ; cin >> a >> b ; 
        --a,--b ;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    vector<bool> vis(n,false) ;

    int cncted = 0 ;
    for1(n){
        if(vis[i]==false){
            int cur = 0 ;
            dfs(i,v,vis);
            cncted++ ;
        }
    }
    cout << (1LL<<n-cncted) ;
    // 2 ^ (n-cncted)
    /*
    comp
    a+b+c = n
    ans = a-1 + b-1 + c-1
    = n - 3
    */

    return 0 ;
}

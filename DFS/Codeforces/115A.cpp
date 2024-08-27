
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

// Depth

int ans = -1 ;
void depth(int v, int d, vvi &adj, vector<bool>&vis){
    vis[v] = true ;
    bool c = false ;
    for(int u : adj[v]){
        if(vis[u]==false){
            depth(u,d+1,adj,vis) ;
            c = true ;
        }
    }
    if(c==false){
        ans = max(ans,d) ;
    }
}



int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    
    int n ; cin >> n ;
    vvi adj(n) ;
    vi candroots ;
    for1(n){
        int a ; cin >> a ;
        if(a==-1){
            candroots.push_back(i) ;
            continue;
        }
        adj[a-1].push_back(i);
    }
    
    vector<bool> vis(n,false) ;
    for(int v : candroots){    
        depth(v,1,adj,vis) ;
    }

    cout << ans ;

    return 0 ;
}


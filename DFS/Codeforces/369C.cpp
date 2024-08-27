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
 
template<class t>
void print(const t a) {cout << a << '\n';}
template<class t>
void print(const vector<t>&v){for(t e:v){cout<<e+1<<' ';}cout<<'\n';}
template<class t>
void print(const vector<vector<t>>&v) {for(vector<t> e:v)print(e);}




vector<int> ans ;

bool dfs (int v, int id, vector< vector< pair<int,bool> > > &adj, map<int,bool>&need, vector<bool>&vis){

    vis[v] = true ;
    bool onesib = false ;
    bool added = false ;
    bool needhere = need[id];
   

    for(pair<int,bool> u : adj[v]){
        if(vis[u.first]==false){
            id++ ;
            onesib = true ;
            if(u.second) need[id] = true ;
            added |= dfs(u.first,id,adj,need,vis) ;
            need[id] = false ;
        }
    }
    if(onesib==false){
        if(need[id]) {ans.push_back(v) ;  return true ;}
        else return false ;
    }
    else{
        if(needhere && !added) {ans.push_back(v) ; added= true ;}
        return added ;
    }  
    
    
}


int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    
    
    int n ; cin >> n ;
    vector< vector< pair<int,bool> > >  adj(n, vector<pair<int,bool>>() ) ;
    
    for1(n-1){
        int a,b,c ; cin >> a >> b >> c;
        --a, --b ;
        adj[a].push_back({b,c==2});
        adj[b].push_back({a,c==2});
    }
    map<int,bool> need ;
    vector<bool> vis(n,false) ;
    dfs(0,0,adj,need,vis) ;
    cout << ans.size() << '\n' ;
    print(ans) ;

    
    return 0 ;
}


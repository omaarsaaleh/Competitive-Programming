
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
void print(const vector<t>&v){for(t e:v){cout<<e+1<<' ';}cout<<'\n';}
template<class t>
void print(const vector<vector<t>>&v) {for(vector<t> e:v)print(e);}

// x  sons  sons of sons ...
// f   x         f
// fix from above first

vector<int>fxd ; 
void dfs(int v, bool parity, vector<bool> &invert, vvi &adj, vector<bool> &vis, vi &now, vi &goal){
    vis[v] = true ;
    bool me = false ;
    if((invert[parity] != parity)) // if inverted before
        now[v] = !now[v] ;
    
    if(now[v]!=goal[v]){ // if not equal the goal fix it and invert the upcoming sons with some parity
        fxd.push_back(v) ;
        invert[parity] = !invert[parity] ;
        me = true ;
    }
    for(int u : adj[v]){
        if(vis[u] == false){
            dfs(u,!parity,invert,adj,vis,now,goal) ;
        }
    }
    if(me) invert[parity] = !invert[parity] ; // undo the invert after finishing
    
}


int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    
    int n ; cin >> n ;
    vvi adj(n) ;

    for1(n-1){
        int a,b ; cin >> a >> b ;
        --a,--b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vi now(n) ;
    for1(n)
        cin >> now[i] ;
    
    vi goal(n) ;
    for1(n)
        cin >> goal[i] ;
    
    
    vector<bool> vis(n,false) ;
    vector<bool> invert(2);
    invert[0]=0, invert[1]=1;
    dfs(0,false,invert,adj,vis,now,goal);
 

    cout << fxd.size() << '\n' ;
    for(int a : fxd){
        cout << a+1 << '\n' ;
    }


    return 0 ;
}

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
    
    int n ; cin >> n ;
    vvi v(n) ;
    for1(n){
        int a ; cin >> a ; 
        --a ;
        v[a].push_back(i);
        v[i].push_back(a);
    }
 
    vector<bool> vis(n,false) ;
 
    int com = 0 ;
    for1(n){
        if(vis[i]==false){
            dfs(i,v,vis);
            com++; 
        }
    }
 
    cout << com ;
 
    return 0 ;
}
 
/*
 
1 2
 
3 4 5
 
1 2
 
3  3  5
 
*/

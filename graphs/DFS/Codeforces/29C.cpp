
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
            dfs(u,adj,vis) ;
        }
    }

    ans.push_back(v) ;
}


int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    
    int n ; cin >> n ; 

    int j = 1 ;
    map<int,int> hashed ;
    vector<int> real(n+3) ;
    vvi adj(n+3) ;
    

    for1(n){
        int a,b ; cin >> a >> b ;
        if(!hashed[a]) {hashed[a]=j; real[j++]=a;}
        if(!hashed[b]) {hashed[b]=j; real[j++]=b;}

        adj[hashed[a]].push_back(hashed[b]) ;
        adj[hashed[b]].push_back(hashed[a]) ;
    }


    int st ;
    for(int i=1;i<=n;i++){
        if(adj[i].size()==1){ st=i ; break;}
    }

    vector<bool> vis(n+3,false) ;

    dfs(st,adj,vis) ;

    for1(n+1){
        cout << real[ans[i]] << ' ' ;
    }
    
    return 0 ;
}

// real[ans[i]]
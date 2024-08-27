
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

// topological sort
// https://onlinejudge.org/external/103/p10305.pdf

void topological_sort_helper(int v, vector<vector<int>>& adj, vector<bool>&vis, vector<int>&sorted){
    vis[v] = true ;

    for(int neigh : adj[v]){
        if(vis[neigh]==false)
            topological_sort_helper(neigh,adj,vis,sorted);   
    }
    sorted.push_back(v) ;
}

vector<int> topological_sort(vector<vector<int>>& adj){
    vector<int> sorted ;

    int sz = adj.size() ;
    vector<bool>vis(sz,false) ;
    for(int i=0 ; i<sz ; i++)    
        if(vis[i]==false) topological_sort_helper(i,adj,vis,sorted);

    reverse(all(sorted)) ;
    return  sorted;
}

int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    
    while(true){
        int n,m ; cin >> n >> m ;
        if(n==0) break;

        vvi adj(n) ; 
        vector<bool> vis(n,false) ;

        for1(m){
            int a,b ; cin >> a >> b ;
            a--,b--;
            adj[a].push_back(b);   
        }

        print(topological_sort(adj)) ;
    }
    return 0 ;
}

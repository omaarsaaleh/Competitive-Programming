
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

// https://onlinejudge.org/external/116/p11686.pdf
// Topological Sort
// a  a->b
// b

bool topological_sort_helper(int v, vector<vector<int>>& adj, vector<int>&vis, vector<int>&sorted){
    
    vis[v] = 1 ;
    bool cyclic = false ;
    for(int neigh : adj[v]){
        if(vis[neigh]==0)
            cyclic |= topological_sort_helper(neigh,adj,vis,sorted);
        else if(vis[neigh]==1)
            return true ;
    }
    vis[v] = 2 ;
    sorted.push_back(v) ;
    return cyclic ;
}

vector<int> topological_sort(vector<vector<int>>& adj){
    vector<int> sorted ;
    int sz = adj.size() ;
    vector<int>vis(sz,0) ;
    for(int i=0 ; i<sz ; i++) { 
        if(vis[i]==false) {
            if(topological_sort_helper(i,adj,vis,sorted)){
                return vector<int>() ;
            }
        }
    }
    reverse(all(sorted)) ;
    return  sorted;
}


int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    
    while(true){
        int n, e ; cin >> n >> e ;
        if(n==0 && e==0) break;

        vvi adj(n);
        for1(e){
            int a,b ; cin >> a >> b ;
            a--,b--;
            adj[a].push_back(b) ;
        }

        vector<int> ans = topological_sort(adj) ;
        if(ans.empty()){
            cout << "IMPOSSIBLE\n" ;
        }
        else{
            for(int v : ans){
                cout << v+1 <<'\n' ;
            }
        }
    }

    return 0 ;
}


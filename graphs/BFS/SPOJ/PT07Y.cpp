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

// Cyclic or not BFS
// if there is more than one visited node (other than the parent), its cyclic
// another way is to keep track of the parent

vector<bool> vis ;
bool isCyclic_u(vvi &adj){
    int n = adj.size() ;
    queue<int> q ;
    
    for1(n){
        if(vis[i]==false){
            q.push(i) ;

            while (!q.empty()){
                int v = q.front() ;
                q.pop() ;
                vis[v] = true ;

                int c = 0 ;
                for(int u : adj[v]){
                    if(vis[u]==true ){
                        c++ ;
                        if(c>1 || u==v) return true ;
                    }
                    else q.push(u) ;

                }
            }
        }
    }
    return false ;
    
}



int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    
    int n, e ; cin >> n >> e ;
    vvi adj(n) ;
    for1(e){
        int a,b ; cin >> a >> b ;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vis.resize(n,false) ;
    
    cout << (isCyclic_u(adj)?  "NO\n": "YES\n") ;
    


    return 0 ;
}


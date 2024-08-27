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
 
vector<int> bfs_real ;

void bfs(vvi adj){

    queue< int >  q ;
    q.push(0);
    vector<bool> vis(adj.size(),false) ;
    vis[0] = true ;

    while (q.empty()==false){
        int v = q.front() ;
        q.pop() ;
        bfs_real.push_back(v+1) ;
        
        for(int u : adj[v]){
            if(vis[u]==false){
                vis[u] = true ;
                q.push(u) ;
            }
        }
    }

}



int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    
    int n ; cin >> n ; 
    vvi adj(n) ;
    for1(n-1){
        int a,b ; cin >> a >> b ;
        --a, --b ;
        adj[a].push_back(b) ;
        adj[b].push_back(a) ;
    }

    int weight = 0 ;
    vector<int> input_order(n) ;
    vector<int> bfs_t(n) ;
    for1(n){
        cin >> bfs_t[i] ;
        input_order[bfs_t[i]-1] = weight++ ;
    }
    
    for(vector<int> &v : adj) sort(all(v),[&](const int &a, const int &b){return input_order[a]<input_order[b];}) ;


    bfs(adj) ;
    // print(bfs_real) ;

    for1(n){
        if(bfs_real[i]!=bfs_t[i]) {cout << "No\n" ; return 0 ;}
    }

    cout << "Yes\n" ;

    return 0 ;
}

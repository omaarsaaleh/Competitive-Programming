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


// parent and siblings color different
// parent, childs, grand child different

//          1
//   2    3     4   5
//   5    4     3   2
//

pair<vector<int>,int> bfs(vvi &adj){

    vector<int> ans(adj.size());
    
    queue<tuple<int,int,int>> q ; // vertex, its color, its father color
    q.push({0,0,-1}) ;
    int l = 1 ;
    if(adj.size()>2) l = 3;
    vector<bool> vis(adj.size(),false) ;
    vis[0] = true ;

    while(q.empty()==false){
        tuple<int,int,int> v = q.front();
        q.pop() ;

        // if a node has n children
        // we need at least n+1 colors

        int siblingspf = 1 ;
        siblingspf+=adj[get<0>(v)].size() ;
        if(siblingspf>l) 
            l = siblingspf ;

        
        int curr_color = 0 ;


        for(int u : adj[get<0>(v)]){
            
            if(vis[u]==false){
                vis[u] = true ;
                
                // the node should be != its father and its grand father AND within the color range
                while(curr_color==get<1>(v) || curr_color==get<2>(v) || curr_color>=l) {
                    curr_color++ ;
                    if(curr_color>=l) curr_color=0 ;
                }
                q.push({u,curr_color,get<1>(v)}) ;
                ans[u] = curr_color++ ;
                
            }
        }

    }

    return {ans,l} ; 
}

//   0 
// 1 2 3
// 2 3 1
// 3 1 2

//  0 
// 1 2
// 0 1
// 2 0


int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    
    
    int n ; cin >> n ;
    vvi adj(n) ;
    
    for1(n-1){
        int a,b ; cin >> a >> b ;
        --a, --b ;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    auto [ ans, l ]= bfs(adj) ;

    cout << l << '\n' ;
    print(ans) ;

    return 0 ;
}
// 0
// 1
// 0
// 1

// 
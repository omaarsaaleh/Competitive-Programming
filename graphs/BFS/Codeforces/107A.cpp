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
#include <fstream>

 
using namespace std;
#define ll long long 
#define all(x) x.begin(), x.end()
#define for1(n) for (int i = 0; i<n; i++)
#define vi vector<int>
#define vvi vector<vector<int>>
#define eache auto &e

vector< tuple<int,int,int> > bfs(vector< vector< pair<int,int> > > &adj, vi &indegree, vi &outdegree){
    int n = adj.size() ;

    vector<bool> vis (n,false)  ;
    vector< tuple<int,int,int> > ans ;
    queue< tuple<int,int,int> > q ;

    for1(n){
        if(indegree[i]==0 && outdegree[i]==1) q.push({i,i,1e6+1}) ;
    }

    while (q.empty()==false){
        tuple<int,int,int> v = q.front() ;
        q.pop() ;

        
        if(adj[get<1>(v)].empty()==false){
            if(vis[adj[get<1>(v)][0].first]==false) {
                pair<int,int> u = adj[get<1>(v)][0] ;
                vis[u.first] = true;
                q.push({get<0>(v), u.first ,min(u.second,get<2>(v))}) ;
            }
        }
        else{
            ans.push_back(v) ;
        }
    }

    return ans ;
     
}





int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    
    int n,p ; cin >> n >> p ;

    vector< vector< pair<int,int> > > adj(n, vector< pair<int,int> >()) ;
    vector<int> indegree(n,0) ;
    vector<int> outdegree(n,0) ;
    for1(p){
        int a,b,d ; cin >> a >> b >> d ;
        --a, --b ; 
        adj[a].push_back({b,d}) ;
        indegree[b]++;
        outdegree[a]++;
    }

    vector< tuple<int,int,int> > ans = bfs(adj,indegree,outdegree) ;
    
    // sort(ans.begin(), ans.end());
    sort(ans.begin(), ans.end(), [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
        return get<0>(a) < get<0>(b);
    });

    cout << ans.size() << '\n' ;
    for (eache : ans){
        cout << get<0>(e)+1 << ' ' << get<1>(e)+1 << ' ' << get<2>(e) << '\n' ;
    }


    return 0 ;
}

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
#define vpii vector<pair<int,int>>
#define vvi vector<vector<int>>
#define vvpii vector<vector<pair<int,int>>>
#define pii pair<int,int>
#define eache auto &e

// Missile Silos
// 144D

template<class t>
void print(const t a) {cout << a << '\n';}
template<class t>
void print(const vector<t>&v){for(t e:v){cout<<e<<' ';}cout<<'\n';}
template<class t>
void print(const vector<vector<t>>&v) {for(vector<t> e:v)print(e);}

vi dis ;

void dijkstra(vvpii &adj, int s){
    int n = adj.size()-1 ;
    dis.resize(n+1, INT_MAX); 
    dis[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0,s});
    while (!q.empty()) {

        int d = q.top().first; 
        int v = q.top().second;
        q.pop();

        for (pii u : adj[v]) {
            int to = u.first, len = u.second;
            if (dis[v] + len < dis[to]) {
                dis[to] = dis[v] + len;
                q.push({dis[to],to});
            }
        }
    }
}



int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    
    
    int v,e, st; cin >> v >> e >> st;
    vvpii adj(v+1,vpii());
    for1(e){
        int a,b,w ; cin >> a >> b >> w; 
        adj[a].push_back({b,w});  
        adj[b].push_back({a,w});
    }
    int l; cin >> l ;
    dijkstra(adj,st);
    map<pii,int> mp ;
    int ans = 0 ;

    for(int i=1 ; i<=v; i++ ){
        if(dis[i]==l) ans++;
        if(dis[i]<l){ // check points
            for(pii ww :adj[i]){
                int a = min(ww.first,i) ;
                int b = max(ww.first,i) ;
                if(dis[i]+ww.second>l){ // there is a point
                    if( ww.second != mp[{a,b}] + l-dis[i] ){ // do not take the same point twice
                        int rest = ww.second - l + dis[i];
                        if( rest + dis[ww.first] < l-dis[i] + dis[i]) continue; // make sure that this is the shortest path to the point
                        ans++;
                        mp[{a,b}] = l-dis[i] ;
                    }
                }
            }
        }
    }

    cout << ans << '\n';


    
    return 0 ;
}

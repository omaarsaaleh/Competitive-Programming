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
#define vvpii vector<vector<pair<int,int>>>
#define pii pair<int,int>
#define eache auto &e
 
template<class t>
void print(const t a) {cout << a << '\n';}
template<class t>
void print(const vector<t>&v){for(t e:v){cout<<e<<' ';}cout<<'\n';}
template<class t>
void print(const vector<vector<t>>&v) {for(vector<t> e:v)print(e);}

// SPOJ
// Highways


int solve(vvpii &adj, int s, int end){
    int n = adj.size()-1 ;
    vector<int> dis(n+1, INT_MAX); 
    vector<int> p(n+1, -1);
    dis[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0,s});
    while (!q.empty()) {

        int d = q.top().first; 
        int v = q.top().second;
        q.pop();

        if (v==end) return dis[v];        

        for (pii u : adj[v]) {
            int to = u.first, len = u.second;
            if (dis[v] + len < dis[to]) {
                dis[to] = dis[v] + len;
                q.push({dis[to],to});
                p[to] = v;
            }
        }
    }
    return -1 ;
}


int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    
    int t ; cin >> t ;
    while(t--){
        int v,e,st,end; cin >> v >> e >> st >> end ;
        vvpii adj(v+1);
        for1(e){
            int a,b,w ; cin >> a >> b >> w ;
            adj[a].push_back({b,w});
            adj[b].push_back({a,w});
        }
        int ans = solve(adj,st,end);
        if(ans==-1) cout << "NONE\n";
        else cout << ans << '\n';
        ans = -1 ;
    }

    return 0 ;
}

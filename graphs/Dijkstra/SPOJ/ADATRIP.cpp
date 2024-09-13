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
#define pll pair<long long,long long>
#define eache auto &e
 
template<class t>
void print(const t a) {cout << a << '\n';}
template<class t>
void print(const vector<t>&v){for(t e:v){cout<<e<<' ';}cout<<'\n';}
template<class t>
void print(const vector<vector<t>>&v) {for(vector<t> e:v)print(e);}
 
// Spoj 
// Ada and Trip
 
vector<ll> dis ;
// const ll LLONG_MAX = 9223372036854775807;
 
pair<ll,ll> dijkstra(vvpii &adj, int s){
    int n = adj.size()-1 ;
    dis.assign(n+1, LLONG_MAX); 
    dis[s] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> q;
    q.push({0,s});
 
    while (!q.empty()) {
 
        ll d = q.top().first; 
        int v = q.top().second;
        q.pop();
 
        if(d!=dis[v]) continue;
 
        for (pii u : adj[v]) {
            int to = u.first, len = u.second;
            if (dis[v] + len < dis[to]) {
                dis[to] = dis[v] + len;
                q.push({dis[to],to});
            }
        }
    }
    ll mx = -1, count = 1 ;

    for(auto v : dis){
        if(v==LLONG_MAX) continue;
        if(v>mx){
            mx = v, count = 1;
        }
        else if(v==mx) count++;
    }
    if(mx==-1) return {0,1};
    return {mx,count};
}
 
 
int main(){
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
 
    int n,m,q; cin >> n >> m >> q ;
    vvpii adj(n+1) ;
    for1(m){
        int a,b,w ; cin >> a >> b >> w ;
        a++,b++;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    
    for1(q){
        int st ; cin >> st ;
        st++;
        auto p = dijkstra(adj,st);
        cout << p.first << ' ' << p.second << '\n';
        
    }
    return 0 ;
}
 
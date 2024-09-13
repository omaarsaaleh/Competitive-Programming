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
#define for1(n) for (ll i = 0; i<n; i++)
#define for2(n) for (ll j = 0; j<n; j++)
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define vvpii vector<vector<pair<ll,ll>>>
#define pii pair<ll,ll>
#define eache auto &e
 
template<class t>
void print(const t a) {cout << a << '\n';}
template<class t>
void print(const vector<t>&v){for(t e:v){cout<<e<<' ';}cout<<'\n';}
template<class t>
void print(const vector<vector<t>>&v) {for(vector<t> e:v)print(e);}


vector<ll> dis ;

void dijkstra_pq(vvpii &adj){
    ll n = adj.size()-1 ;
    
    for(int s=1 ; s<=n ; s++){
        priority_queue<pii, vector<pii>, greater<pii>> q;
        vector<ll> dis2 = dis ;
        q.push({dis[s],s});
        ll mn = dis[s];
        
        while (!q.empty()) {

            ll v = q.top().second; 
            ll d_v = q.top().first;
            q.pop();

            if (d_v != dis2[v]) continue;
            
            for (auto u : adj[v]) {
                ll to = u.first, len = u.second;
                if (dis2[v] + len < dis2[to]) {
                    // does not support deletion
                    dis2[to] = dis2[v] + len;
                    dis[to] = min(dis[to], dis2[to]);
                    q.push({dis2[to],to});
                }
            }
        }
        
        
    }
}



int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    
    ll n, e ; cin >> n >> e ;
    vvpii adj(n+1);
    for1(e){
        ll a,b,w ; cin >> a >> b >> w;
        w*=2;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    dis.resize(n+1);
    for(ll i=1; i<=n; i++) cin >> dis[i] ;

    dijkstra_pq(adj);

    for(ll i=1 ; i<=n ;i++) cout << dis[i] << ' ';

    return 0 ;
}
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
#define vpii vector<pair<ll,ll>>
#define vvi vector<vector<ll>>
#define vvll vector<vector<long long>>
#define vvpii vector<vector<pair<ll,ll>>>
#define pii pair<ll,ll>
#define eache auto &e

 
template<class t>
void print(const t a) {cout << a << '\n';}
template<class t>
void print(const vector<t>&v){for(t e:v){cout<<e<<' ';}cout<<'\n';}
template<class t>
void print(const vector<vector<t>>&v) {for(vector<t> e:v)print(e);}

// Codeforces 449B
// Jzzhu and Cities

vector<pair<ll,ll>> dis ;
struct Node{
    ll v,w;
    ll train;
    Node(ll v, ll w, ll t) : v(v),w(w), train(t){}
    Node() : v(-1),w(LLONG_MAX), train(0){}
};

ll used = 0 ;

void dijkstra(vector<vector<Node>> &adj ){
    ll n = adj.size()-1 ;
    dis.resize(n+1, {LLONG_MAX,0}); 
    dis[1] = {0,0};
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0,1});
    while (!q.empty()) {

        ll v = q.top().second; 
        ll d = q.top().first; 
        q.pop();

        if(d!=dis[v].first) continue;

        for (auto u : adj[v]) {
            ll to = u.v;
            ll len = u.w;
            ll train = u.train ;
            if (dis[v].first + len < dis[to].first) {
                dis[to] = {dis[v].first + len, train};
                q.push({dis[to].first,to});
            }
            else if(dis[v].first + len == dis[to].first && !train) {
                dis[to].second = 0;
            }
        }
    }
    
}


int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    
    ll n,m,k ; cin >> n >> m >> k ;
    vector<vector<Node>> adj(n+1);
    for1(m){
        ll a,b,w ; cin >> a >> b >> w ;
        adj[a].push_back(Node(b,w,0));
        adj[b].push_back(Node(a,w,0));
    }

    ll hh = 1 ;
    for1(k){
        ll a,w ; cin >> a >> w ;
        adj[a].push_back(Node(1,w,hh));
        adj[1].push_back(Node(a,w,hh++));
    }
    vector<bool> tt(k+2,false) ;
    dijkstra(adj);
    for(eache:dis){
        if(e.second){
            if(tt[e.second]==false){
                tt[e.second] = true ;
                used ++ ;
            }
        }
    }
    cout << k-used << '\n';

    return 0 ;
}
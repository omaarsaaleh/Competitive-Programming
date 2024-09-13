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
#define vvll vector<vector<long long>>
#define vvpii vector<vector<pair<int,int>>>
#define pii pair<int,int>
#define eache auto &e

 
template<class t>
void print(const t a) {cout << a << '\n';}
template<class t>
void print(const vector<t>&v){for(t e:v){cout<<e<<' ';}cout<<'\n';}
template<class t>
void print(const vector<vector<t>>&v) {for(vector<t> e:v)print(e);}

// Codeforces 1433G
// Reducing Delivery Cost

vector<ll> dis ;
vector<int> p ;
vvll from_to ;

void dijkstra(vvpii &adj, int s ){
    int n = adj.size()-1 ;
    dis.assign(n+1, LLONG_MAX); 
    p.assign(n+1, -1);
    dis[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0,s});
    while (!q.empty()) {

        int v = q.top().second; 
        int d = q.top().first; 
        q.pop();

        if(d!=dis[v]) continue;

        for (auto u : adj[v]) {
            int to = u.first;
            ll len = u.second;
            if (dis[v] + len < dis[to]) {
                dis[to] = dis[v] + len;
                q.push({dis[to],to});
                p[to] = v;
            }
        }
    }
    from_to.push_back(dis);
}




int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    
    int n,m,k ; cin >> n >> m >> k ;
    vvpii adj(n+1);
    vector<pii> edges ;
    from_to.push_back(vector<ll>());
    for1(m){
        int a,b,c ; cin >> a >> b >> c ;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
        edges.push_back({a,b});
    }
    for(int i=1 ; i<=n ; i++) dijkstra(adj,i) ;
    vector<pii> deliveries ;
    for1(k){
        int st,end ; cin >> st >> end ;
        deliveries.push_back({st,end});
    }
    
    ll ans = LLONG_MAX ;
    for(pii mm : edges ){ // m
        ll cur = 0 ;
        for(pii kk : deliveries){ // k
            cur += min(from_to[kk.first][kk.second], 
                min(from_to[kk.first][mm.first]+from_to[mm.second][kk.second], 
                    from_to[kk.second][mm.first]+from_to[mm.second][kk.first]
                )
            ) ;
        }
        ans = min(ans,cur);
    }
    cout << ans << '\n' ;

    return 0 ;
}
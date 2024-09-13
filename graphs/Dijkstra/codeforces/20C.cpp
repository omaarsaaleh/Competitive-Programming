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

 
template<class t>
void print(const t a) {cout << a << '\n';}
template<class t>
void print(const vector<t>&v){for(t e:v){cout<<e<<' ';}cout<<'\n';}
template<class t>
void print(const vector<vector<t>>&v) {for(vector<t> e:v)print(e);}

// Codeforces 20C
// Dijkstra?

vector<ll> dis ;
vector<int> p ;


void dijkstra(vvpii &adj, int s){
    int n = adj.size()-1 ;
    dis.resize(n+1, LLONG_MAX); 
    p.resize(n+1, -1);
    dis[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0,s});
    while (!q.empty()) {

        int v = q.top().second; 
        q.pop();

        
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
}

vector<int> restore_path(int s, int t) {
    
    vector<int> path;
    for (int v = t; v != s; v = p[v])
        path.push_back(v);
    
    path.push_back(s);

    reverse(path.begin(), path.end());
    return path;
}


int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    
    int n,e ; cin >> n >> e ;
    vvpii adj(n+1,vpii());
    for1(e){
        int a,b,w ; cin >> a >> b >> w ;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }

    dijkstra(adj,1);

    if(p[n]==-1) cout << "-1";
    else{
        vi v = restore_path(1,n);
        print(v);
    }
    
    

    return 0 ;
}
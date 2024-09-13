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

// UVa 10436
// Cheapest way
// https://onlinejudge.org/external/104/10436.pdf

vector<int> p;

int dijkstra(vvpii &adj, vi taxes, int s, int end){
    
    int n = adj.size()-1 ;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    p.assign(n+1,-1);
    vector<int> dis(n+1, 2e9);
    dis[s] = taxes[s] ;
    q.push({dis[s],s});
    while (!q.empty()) {

        int d = q.top().first; 
        int v = q.top().second;
        q.pop();

        if (v==end) {return dis[v]; }

        for (pii u : adj[v]) {
            int to = u.first, len = u.second;

            if (dis[v] + len + taxes[to] < dis[to]) {
                dis[to] = dis[v] + len + taxes[to];
                q.push({dis[to],to});
                p[to] = v;
            }
        }
    }
    return -1 ;
}

vector<string> restore_path(int s, int end, const vector<string>&un_mp) {
    
    vector<string> path;
    for (int v = end; v != s; v = p[v])
        path.push_back(un_mp[v]);
    
    path.push_back(un_mp[s]);

    reverse(path.begin(), path.end());
    return path;
}


int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    
    int t ; cin >> t ;
    for(int gh = 1 ; gh<=t ; gh++){
        int v ; cin >> v ;
        vector<int> taxes(v+1);
        int mp_factor = 1 ;
        map<string,int> mp ;
        vector<string> un_mp(v+1);
        for1(v){
            string s ; cin >> s ;
            mp[s] = mp_factor ;
            cin >> taxes[mp_factor] ;
            un_mp[mp_factor++] = s ;
        }

        int e ; cin >> e ;
        vvpii adj(v+1);
        for1(e){
            string a,b ; cin >> a >> b ;
            int w ; cin >> w ;
            adj[mp[a]].push_back({mp[b],w*2});
            adj[mp[b]].push_back({mp[a],w*2});
        }

        int q ; cin >> q ;
        cout << "Map #" << gh << '\n' ;
        for1(q){
            string _a,_b ; cin >> _a >> _b ;
            double sts ; cin >> sts ;
            int a = mp[_a],  b = mp[_b];
            
            double money = dijkstra(adj,taxes,a,b) ;
            money += money*0.1 ;
            money /= sts ;
            vector<string> path = restore_path(a,b,un_mp);

            cout << "Query #" << i+1 << '\n';
            for(int j=0 ; j<path.size() ; j++){
                cout << path[j] ;
                if(j!=path.size()-1) cout << ' ';
                else cout << '\n';
            }
            
            cout << "Each passenger has to pay : " << fixed << setprecision(2) << money << " taka\n";
        }
        if(gh!=t) cout << '\n';

    }

    return 0 ;
}

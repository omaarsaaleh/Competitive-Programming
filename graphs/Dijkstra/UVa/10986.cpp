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

// 10986 Sending email
// https://onlinejudge.org/external/109/10986.pdf

vi dis ;

int dijkstra(vvpii &adj, int s, int end){
    int n = adj.size()-1 ;
    dis.assign(n+1, INT_MAX); 
    dis[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0,s});
    while (!q.empty()) {

        int d = q.top().first; 
        int v = q.top().second;
        q.pop();

        if(d!=dis[v]) continue;
        if (v==end) return d;        

        for (pii u : adj[v]) {
            int to = u.first, len = u.second;
            if (dis[v] + len < dis[to]) {
                dis[to] = dis[v] + len;
                q.push({dis[to],to});
            }
        }
    }
    return -1 ;
}


int main(){
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);

    int t ; cin >> t ;
    for (int kk = 1 ; kk<=t ; kk++){
        int n,m,st,end; cin >> n >> m >> st >> end;
        st++,end++;
        vvpii adj(n+1) ;
        for1(m){
            int a,b,w ; cin >> a >> b >> w ;
            a++,b++;
            adj[a].push_back({b,w});
            adj[b].push_back({a,w});
        }
        int ans = dijkstra(adj,st,end);

        cout << "Case #" << kk << ": ";
        if(ans==-1) cout << "unreachable";
        else cout << ans ;
        cout << '\n';

    }
    

    return 0 ;
}
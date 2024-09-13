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
#define pll pair<long long,long long>
#define eache auto &e

 
template<class t>
void print(const t a) {cout << a << '\n';}
template<class t>
void print(const vector<t>&v){for(t e:v){cout<<e<<' ';}cout<<'\n';}
template<class t>
void print(const vector<vector<t>>&v) {for(vector<t> e:v)print(e);}


vector<ll> dis ;

struct Road{
    int wisdom, cost, to ;
    Road(int to,int w,int c) : wisdom(w),cost(c),to(to){}
};

int mx_cost ;

bool dijkstra(vector<vector<Road>> &adj, int mx_wisdom){
    int n = adj.size()-1 ;
    dis.assign(n+1, LLONG_MAX); 
    dis[1] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> q;
    q.push({0,1});
    while (!q.empty()) {

        ll d = q.top().first; 
        int v = q.top().second;
        q.pop();
        
        if (v==n)
            return dis[v]<mx_cost;

        for (Road u : adj[v]) {
            int to = u.to, len = u.cost, wis = u.wisdom ;

            if(wis > mx_wisdom) continue;
            if (dis[v] + len < dis[to]) {
                dis[to] = dis[v] + len;
                q.push({dis[to],to});
            }
        }
    }
    return false ;
}



int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    
    int t ; cin >> t ;
    while(t--){
        int n,m; cin >> n >> m >> mx_cost ;

        vector<vector<Road>> adj(n+1) ;
        set<int> wis_st ;
        for1(m){
            int a,b,c,w ; cin >> a >> b >> c >> w ;
            adj[a].push_back(Road(b,w,c));
            adj[b].push_back(Road(a,w,c));
            wis_st.insert(w);
        }
        vector<int> wisdoms(all(wis_st)) ;

        int low = 0, high = wisdoms.size()-1;
        int cr = -1 ;
        while(low<=high){
            int mid = (high-low)/2 + low ;
            if(dijkstra(adj,wisdoms[mid])) {
                cr = wisdoms[mid];
                high = mid-1 ;
            }
            else low = mid+1 ;
        }
        cout << cr << '\n';


    }

}
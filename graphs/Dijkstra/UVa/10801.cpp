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

// UVa 10801
// Lift Hopping
// https://onlinejudge.org/external/108/10801.pdf

const int INT_MAX = 2e9;


vi dis ;
struct Current{
    int num, prev ;
    Current(int n, int p) : num(n), prev(p){}
};
auto cmp = [](const pair<int, Current>& a, const pair<int, Current>& b) {
    return a.first > b.first; 
};
priority_queue<pair<int,Current>, vector<pair<int,Current>>, decltype(cmp)> q(cmp);


int dijkstra(vvi &adj, vi &cost ,int end){
    while (!q.empty()) {

        int d = q.top().first; 
        int v = q.top().second.num;
        int prev = q.top().second.prev;
        q.pop();


        for (int to : adj[v]) {
            // floor to elevator
            // put all excepet the prev
            if(v<101){
                if (to == prev) continue;
                q.push({d+60,Current(to,v)});
                continue;
            }

            // elevator to floor
            int len = (cost[v-101]*abs(to-prev)) ;
            if (d + len < dis[to]) {
                dis[to] = d + len;
                q.push({dis[to],Current(to,v)});
            }

        }
    }
    return dis[end] ;
}


int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    
    int v,end ; 
    while (cin >> v >> end ){
        vector<int> cost(v);
        for1(v) cin >> cost[i];
        dis.assign(v+1+100, INT_MAX); 

        vvi adj(100+v+1,vi());
        
        cin.ignore();
        for1(v){    
            string line;
            getline(cin,line);
            istringstream stream(line);
            int a;
            while (stream >> a) {
                a++;
                if(a==1){
                    q.push({0,Current(i+101,1)});
                    dis[1] = 0;
                    continue;
                }
                adj[i+101].push_back(a);  
                adj[a].push_back(i+101);
            }
        }
        int ans = dijkstra(adj,cost,end+1);
        if(ans==INT_MAX ) cout << "IMPOSSIBLE";
        else cout << ans ;
        cout << '\n';
    }
    
    return 0 ;
}

/*
101 0
102 0
103 0
104 0
105 0

0 + i*cost

from floor to elevator always put
except if its the floor its coming from

q num + current cost
loop adj[num]
if(num = elevator) current_cost + cost_elev * (to-num), to
if(num = floor)
    if(to!=from_where_we_come)
        current_cost + 60, elev_num 
        

*/
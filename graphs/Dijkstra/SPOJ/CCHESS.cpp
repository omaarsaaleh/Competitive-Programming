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
#define vvvpii vector<vector<vector<pair<int,int>>>>
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
// COSTLY CHESS

vector < pair<int,int> > moves =
{ {-2,-1}, {-2,1}, {-1,2}, {-1,-2}, {1,2}, {1,-2}, {2,1}, {2,-1}};
 
bool isvaildmove(int c, int i){
    return (c >= 1 && c <= 8) && (i >= 1 && i <= 8) ; 
}

 
vector<vector<int>> dis ;

struct Cell{
    int x,y ; 
    Cell(int x, int y) : x(x), y(y) {}
};
auto cmp = [](const pair<int, Cell>& a, const pair<int, Cell>& b) {
    return a.first > b.first; 
};


int dijkstra(vvvpii &adj, int x, int y, int x_end, int y_end){
    dis.assign(9, vector<int>(9, INT_MAX) ); 
    dis[x][y] = 0;
    priority_queue<pair<int,Cell>, vector<pair<int,Cell>>, decltype(cmp)> q(cmp);
    q.push({0,Cell(x,y)});
    while (!q.empty()) {
 
        ll d = q.top().first; 
        Cell v = q.top().second;
        q.pop();
 
        if(d!=dis[v.x][v.y]) continue;
        if(v.x==x_end && v.y==y_end) return dis[v.x][v.y];
 
        for (pii u : adj[v.x][v.y]) {
            
            int x_n = u.first, y_n = u.second;
            int len = (v.x-1)*(x_n-1) + (v.y-1)*(y_n-1) ; 
            if (dis[v.x][v.y] + len < dis[x_n][y_n]) {
                dis[x_n][y_n] = dis[v.x][v.y] + len;
                q.push({dis[x_n][y_n],Cell(x_n,y_n)});
            }
        }
    }
    return -1;

}
 
 
int main(){
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
 
    vvvpii adj(9,vvpii(9)) ;
    for(int i=1; i<=8 ; i++){
        for(int j=1; j<=8 ; j++){ 
            for(auto mv : moves){
                int x_n = i+mv.first ;
                int y_n = j+mv.second ;
                if(isvaildmove(x_n,y_n)){
                    adj[i][j].push_back({x_n,y_n});
                }
            }
        }
    }
    
    int x,y,x_n,y_n;
    while(cin >> x >> y >> x_n >> y_n){
        x++,y++,x_n++,y_n++;
        cout << dijkstra(adj,x,y,x_n,y_n) << '\n';    
    }
    return 0 ;
}
 
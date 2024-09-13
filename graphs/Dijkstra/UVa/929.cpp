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
#define vvvi vector<vector<vector<int>>>
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
 
// 929 Number Maze
// https://onlinejudge.org/external/9/929.html

vector < pair<int,int> > moves =
{ {0,-1},{0,1},{-1,0},{1,0} };

// const int INT_MAX = 2e9 ;

int N ; 
int M ;

bool isvaildmove(int c, int i){
    return (c >= 1 && c <= N) && (i >= 1 && i <= M) ; 
}
 
vector<vector<int>> dis ;

struct Cell{
    int x,y ; 
    Cell(int x, int y) : x(x), y(y) {}
};
auto cmp = [](const pair<int, Cell>& a, const pair<int, Cell>& b) {
    return a.first > b.first; 
};


int dijkstra(vvi &cost){
    priority_queue<pair<int,Cell>, vector<pair<int,Cell>>, decltype(cmp)> q(cmp);
    vvi dis(N+1,vi(M+1,INT_MAX));
    dis[1][1] = cost[1][1] ;
    q.push({cost[1][1],Cell(1,1)});
    while (!q.empty()) {
 
        ll d = q.top().first; 
        Cell v = q.top().second;
        q.pop();
 
        if(d!=dis[v.x][v.y]) continue;
 
        for(auto mv : moves){
            int x_n = v.x+mv.first ;
            int y_n = v.y+mv.second ;
            
            if(isvaildmove(x_n,y_n)){
                if (dis[v.x][v.y] + cost[x_n][y_n] < dis[x_n][y_n]) {
                    dis[x_n][y_n] = dis[v.x][v.y] + cost[x_n][y_n];
                    q.push({dis[x_n][y_n],Cell(x_n,y_n)});
                }
            }
        }
    }
    return dis[N][M];

}

int main(){
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
 
    int t; cin >> t ; 
    while(t--){
        cin >> N >> M ;
        vvi cost(N+1,vi(M+1));

        for(int i=1 ; i<=N ; i++)
            for(int j=1 ; j<=M ; j++)
                cin >> cost[i][j];
            
        cout << dijkstra(cost) << '\n';    
    }
    return 0 ;
}
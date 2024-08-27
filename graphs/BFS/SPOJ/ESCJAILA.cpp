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
#define pi pair<int,int>
#define eache auto &e
 
template<class t>
void print(const t a) {cout << a << '\n';}
template<class t>
void print(const vector<t>&v){for(t e:v){cout<<e+1<<' ';}cout<<'\n';}
template<class t>
void print(const vector<vector<t>>&v) {for(vector<t> e:v)print(e);}


vector<int> ans ;


const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

bool isValid(int n, int m, int x, int y){
    return (x>-1 && y>-1 && x<n && y<m ) ;
}

struct Point {
    int x, y, distance;
    bool isopen ;
    Point(int x, int y, bool o, int d) : x(x), y(y), isopen(o), distance(d) {}
};

int bfs(pair<int,int> st, vector<string> &graph, vector<vector<vector<bool>>> &vis, int n, int m){

    queue<Point> q;
    q.push(Point(st.first,st.second,false,0)) ;
    while(q.empty()==false){
        Point p = q.front() ;
        q.pop() ;
        for1(4){
            int xn = p.x + dx[i] ;
            int yn = p.y + dy[i] ;

            if(isValid(n,m,xn,yn)){
                if (vis[xn][yn][p.isopen]==false && graph[xn][yn] != 'W' && !(p.isopen==false && graph[xn][yn] == 'D')){
                    bool on = p.isopen;
                    if (graph[xn][yn] == 'O')
                        on = true;
                    else if (graph[xn][yn] == 'C')
                        on = false;
                    vis[xn][yn][on] = true;
                    q.push(Point(xn, yn, on, p.distance + 1));
                }
                
            }
            else return p.distance+1 ;
            // first out
        }
    }
    return -1 ;
}

int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    
    
    while (true){
        int n,m ; cin >> n >> m ;
        if(n==-1) break;
        vector<string> graph ;
        pair<int,int> st ;
        for1(n){
            string s ; cin >> s ; 
            graph.push_back(s) ;
            for2(m)
                if(s[j]=='H') st = {i,j} ;
        }

        vector<vector<vector<bool>>> vis(n,vector<vector<bool>>(m,vector<bool>(2))) ;
        cout << bfs(st,graph,vis,n,m) << '\n';
    }
    

    

    return 0 ;
}


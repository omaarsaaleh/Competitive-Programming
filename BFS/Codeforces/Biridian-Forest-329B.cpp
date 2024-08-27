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
#include <tuple>
 
using namespace std;
#define ll long long 
#define all(x) x.begin(), x.end()
#define for1(n) for (int i = 0; i<n; i++)
#define for2(n) for (int j = 0; j<n; j++)
#define vi vector<int>
#define vvi vector<vector<int>>
#define eache auto &e
 
template<class t>
void print(const t a) {cout << a << '\n';}
template<class t>
void print(const vector<t>&v){for(t e:v){cout<<e<<' ';}cout<<'\n';}
template<class t>
void print(const vector<vector<t>>&v) {for(vector<t> e:v)print(e);}
 
vector<int> dx = {0,0,1,-1};
vector<int> dy = {1,-1,0,0};

int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    
    int n,m ; cin >> n >> m ;
    vector< vector<char> > graph (n, vector<char>(m)) ;
    queue< tuple<int,int,int> > q;
    vector< pair<int,int >> enemies ;
    pair<int,int> st ;
    for1(n)
        for2(m){
            cin >> graph[i][j] ;
            if(graph[i][j]=='E') q.push({i,j,0}) ;
            else if(isdigit(graph[i][j]) && graph[i][j]!='0'){
                enemies.push_back({i,j}) ;
            }
            else if(graph[i][j]=='S'){
                st = {i,j} ;
            }
        }
    vector< vector<pair<int,int> > > distance (n, vector<pair<int,int>>(m)) ; // dist, num of enemies
    distance[get<0>(q.front())][get<1>(q.front())] = {0,0} ;
    
    
    while(!q.empty()){
        tuple<int,int,int> v = q.front() ;
        q.pop() ;

        for1(4){
            int n_row = dy[i] + get<0>(v)  ; 
            int n_col = dx[i] + get<1>(v) ;
            if((n_row > -1  && n_row < graph.size()) && (n_col > -1 && n_col < graph[0].size())){
                if(graph[n_row][n_col] != 'T'){
                    distance[n_row][n_col] = { get<2>(v)+1, (isdigit(graph[n_row][n_col])? graph[n_row][n_col]-'0' : 0) };
                    q.push({n_row,n_col,get<2>(v)+1}) ;
                    graph[n_row][n_col] = 'T' ;

                }
            }
        }
    }

    int pathL = distance[st.first][st.second].first ;
    int fights = 0 ;
    for(pair<int,int> enemy : enemies)
        if(distance[enemy.first][enemy.second].first <= pathL) fights+= distance[enemy.first][enemy.second].second ;
    
    cout << fights <<'\n';

        
    return 0 ;
}



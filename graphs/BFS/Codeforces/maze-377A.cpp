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
#define eache auto &e
 
template<class t>
void print(const t a) {cout << a << '\n';}
template<class t>
void print(const vector<t>&v){for(t e:v){cout<<e;}cout<<'\n';}
template<class t>
void print(const vector<vector<t>>&v) {for(vector<t> e:v)print(e);}
 

vector<int> dx = {0,0,1,-1};
vector<int> dy = {1,-1,0,0};

int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);

    int n,m,k ; cin >> n >> m >> k ;

    vector< vector<char> >  graph(n,vector<char>(m)) ;
    pair<int,int> root ;
    vector< pair<int,int> > empty ;

    for1(n){
        for2(m){
            cin >> graph[i][j] ;
            if(graph[i][j]=='.') root = {i,j} ;
        }
    } 

    queue< pair<int,int> > q ;
    q.push(root) ;

    vector< vector<bool> >  vis(n,vector<bool>(m,false)) ;
    vis[get<0>(root)][get<1>(root)] = true ;

    while(!q.empty()){
        pair<int,int> v = q.front() ;
        q.pop();
        
        empty.push_back(v) ;

        for1(4){
            int n_row = dx[i] + get<0>(v) ;
            int n_col = dy[i] + get<1>(v) ;

            if((n_row > -1  && n_row < graph.size()) && (n_col > -1 && n_col < graph[0].size())){
                if(graph[n_row][n_col]=='.' && !vis[n_row][n_col]){
                    q.push({n_row,n_col}) ;
                    vis[n_row][n_col] = true ;

                }
            }
        }
    }

    for1(k){
        pair<int,int> v = empty.back();
        graph[get<0>(v)][get<1>(v)] = 'X' ;
        empty.pop_back() ;
    }

    print(graph) ;

    return 0 ;
}



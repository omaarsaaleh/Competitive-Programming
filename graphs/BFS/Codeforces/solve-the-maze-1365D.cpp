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
void print(const vector<t>&v){for(t e:v){cout<<e<<' ';}cout<<'\n';}
template<class t>
void print(const vector<vector<t>>&v) {for(vector<t> e:v)print(e);}
 
vector<int> dx = {0,0,1,-1};
vector<int> dy = {1,-1,0,0};

int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    
    int t ; cin >> t ;
    while(t--){
        int n,m ; cin >> n >> m ;
        vector< vector<char> > graph (n,vector<char>(m)) ;

        vector< pair<int,int> > baddies ; 
        int goodies = 0;

        for1(n){
            for2(m){
                cin >> graph[i][j] ;
                if(graph[i][j]=='B') baddies.push_back({i,j}) ;
                else if(graph[i][j]=='G') goodies++ ;
            }
        }
        
        bool done = false ;
        for(pair<int,int> baddy : baddies){
            for1(4){
                int n_row = baddy.first + dx[i];
                int n_col = baddy.second + dy[i];
                if((n_row > -1  && n_row < graph.size()) && (n_col > -1 && n_col < graph[0].size())){
                    if(graph[n_row][n_col]=='G') {done = true ; break;}
                    else if(graph[n_row][n_col]=='.'){
                        graph[n_row][n_col]='#';
                    }
                }

            }
            if(done) break;
        }
        
        if(done || ( graph.back().back()=='#' && goodies>0) ){cout<<"NO\n"; continue;}
        

        queue< pair<int,int> > q ;
        q.push({n-1,m-1}) ;
        graph[n-1][m-1] = '#' ;
        int vis_goodies = 0 ;

        while (!q.empty()){
            pair<int,int> v = q.front();
            q.pop() ;

            for1(4){
                int n_row = v.first + dx[i];
                int n_col = v.second + dy[i];
                if((n_row > -1  && n_row < graph.size()) && (n_col > -1 && n_col < graph[0].size())){
                    if(graph[n_row][n_col]!='#'){
                        q.push({n_row,n_col}) ;
                        if(graph[n_row][n_col]=='G') vis_goodies++ ;
                        graph[n_row][n_col]='#';
                    }
                }
            }
        }

        cout << ((vis_goodies==goodies)? "YES\n" : "NO\n") ;

    }

    return 0 ;
}
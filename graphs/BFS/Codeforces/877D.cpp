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
    
    int n,m, k ; cin >> n >> m >> k ;
    vector<vector<char>> graph (n,vector<char>(m)) ;

    for1(n){
        for2(m){
            cin >> graph[i][j] ;
        }
    }    
    pair<int,int> st, end ;
    cin >> st.first >> st.second ;
    cin >> end.first >> end.second ;

    st.first-- ; st.second-- ; end.first-- ; end.second-- ;

    queue< pair<int,int> > q ;
    q.push(st) ;
    vector<vector<int>> d (n,vector<int>(m,INT_MAX)) ;
    d[st.first][st.second] = 0 ;
    graph[st.first][st.second] = '$' ;

    
    while (!q.empty()){
        pair<int,int> v = q.front() ;
        q.pop() ;

        for1(2){ // vertical
            for(int j=1 ; j<=k ; j++ ){
                int n_row = dy[i] * j + get<0>(v)  ; 
                int n_col = get<1>(v) ;
                if((n_row > -1  && n_row < graph.size()) && (n_col > -1 && n_col < graph[0].size())){
                    if(graph[n_row][n_col]=='#') break;
                    if(d[n_row][n_col] <= d[get<0>(v)][get<1>(v)]) break;

                    if(graph[n_row][n_col]=='.'){
                        d[n_row][n_col] = d[get<0>(v)][get<1>(v)] + 1 ;
                        graph[n_row][n_col] = '$' ;
                        q.push({n_row,n_col}) ;
                    }
                }
                else break;
            }
        }
        for(int i=2; i<4 ; i++){ // horizontal
            for(int j=1 ; j<=k ; j++ ){
                int n_row = get<0>(v)  ; 
                int n_col = dx[i] * j + get<1>(v) ;
                if((n_row > -1  && n_row < graph.size()) && (n_col > -1 && n_col < graph[0].size())){
                    if(graph[n_row][n_col]=='#') break;
                    if(d[n_row][n_col] <= d[get<0>(v)][get<1>(v)]) break;
                    // stop if cell = # and $ wrong as there could be a better direction than the first one found 
                    // stop if cell = # only time limit
                    // stop if cell = # or dis(ch) <= dis(par) no need for it as it

                    if(graph[n_row][n_col]=='.'){
                        d[n_row][n_col] = d[get<0>(v)][get<1>(v)] + 1 ;
                        graph[n_row][n_col] = '$' ;
                        q.push({n_row,n_col}) ;
                    }
                }
                else break;
            }
        }
    }

    cout << (d[end.first][end.second]==INT_MAX ? -1 : d[end.first][end.second]) << '\n' ;
    

    return 0 ;
}

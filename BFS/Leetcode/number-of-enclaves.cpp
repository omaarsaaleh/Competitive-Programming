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
#define vi vector<int>
#define vvi vector<vector<int>>
#define eache auto &e
 
template<class t>
void print(const t a) {cout << a << '\n';}
template<class t>
void print(const vector<t>&v){for(t e:v){cout<<e<<' ';}cout<<'\n';}
template<class t>
void print(const vector<vector<t>>&v) {for(vector<t> e:v)print(e);}
 
vector<pair<int,int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}} ;

int numEnclaves(vector<vector<int>>& grid) {
    int rows = grid.size() ;       
    int cols = grid[0].size() ; 
    
    
    queue< pair<int,int> > q ;
    vector < vector<bool> > vis (grid.size(),vector<bool>(grid[0].size(),false)) ;

    for(int i : {0,rows-1})
        for(int j=0 ; j<cols ; j++)
            if(grid[i][j]){ q.push({i,j}) ; vis[i][j] = true ;}
          
    for(int i : {0,cols-1})
        for(int j=0 ; j<rows ; j++)
            if(grid[j][i]){ q.push({j,i}) ; vis[i][j] = true ;}

    while(!q.empty()){
        pair<int,int> v = q.front() ;
        grid[v.first][v.second] = 0 ;
        q.pop() ;

        for(pair<int,int> d : dir){
            int n_row = d.first + v.first  ; 
            int n_col = d.second + v.second ;
            if((n_row > -1  && n_row < grid.size()) && (n_col > -1 && n_col < grid[0].size())){
                if(grid[n_row][n_col] == 1 && !vis[n_row][n_col]){
                    q.push({n_row,n_col}) ;
                    vis[n_row][n_col] = true ;
                    grid[n_row][n_col] = 0 ;
                }
            }
        }
    }

    int ones = 0 ;
    
    for(int i=0 ; i<rows ; i++)
        for(int j=0 ; j<cols ; j++)
            if(grid[i][j]) ones++ ;
    
    return ones ;

  
}

int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    
    // vvi g = {{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}} ;
    vvi g = {{0,1,1,0},{0,0,1,0},{0,0,1,0},{0,0,0,0}} ;

    print(numEnclaves(g)) ;

    return 0 ;
}



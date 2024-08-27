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


int bfs(queue< pair< pair<int,int>,int> > &q, vector<vector<int>>& grid){
    
    int time = 0 ;
    while(!q.empty()){
        
        int row = q.front().first.first ;
        int col = q.front().first.second ;
        time = max(time,q.front().second) ;
        

        for(pair<int,int> d : dir){
            int n_row = d.first + row  ; 
            int n_col = d.second + col ;
            if((n_row > -1  && n_row < grid.size()) && (n_col > -1 && n_col < grid[0].size())){
                if(grid[n_row][n_col] == 1){
                    grid[n_row][n_col] = 2 ;
                    q.push({{n_row,n_col}, q.front().second+1}) ;
                }
            }
        }
        q.pop() ;

    }

    return time ;
}

int orangesRotting(vector<vector<int>>& grid) {

    queue< pair< pair<int,int>,int> > q ;
    // { {row,col}, time

    for(int i=0 ; i<grid.size() ; i++){
        for(int j=0 ; j<grid[0].size() ; j++){
            if(grid[i][j] == 2){   
                q.push({{i,j},0}) ;   
            }
        }
    }

    int t = bfs(q,grid) ;

    for(int i=0 ; i<grid.size() ; i++)
        for(int j=0 ; j<grid[0].size() ; j++)
            if(grid[i][j] == 1)  
                return -1 ;   
            
        

    return t ;


}


int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    

    

    return 0 ;
}



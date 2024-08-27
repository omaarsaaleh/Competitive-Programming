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
 

// get all the outliers o and its adjacents
// mark the rest as X

vector<pair<int,int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}} ;


vector<vector<char>> solve(vector<vector<char>>& board) {
    queue< pair <int,int> > q ;
    for(int i : {0,(int)(board.size()-1)})
        for(int j=0 ; j<board[0].size() ; j++)
            if(board[i][j]=='O') q.push({i,j}) ;
    
    for(int i : {0,(int)(board[0].size()-1)})
        for(int j=0 ; j<board.size() ; j++)
            if(board[j][i]=='O') q.push({j,i}) ;
    
    
    while(!q.empty()){
        pair<int,int> v = q.front(); 
        q.pop() ;
        board[v.first][v.second] = '*' ;
        
        for(pair<int,int> d : dir){
            int n_row = d.first + v.first ; 
            int n_col = d.second + v.second ;
            if((n_row > -1  && n_row < board.size()) && (n_col > -1 && n_col < board[0].size())){
                if(board[n_row][n_col]=='O'){
                    q.push({n_row,n_col}) ;
                }
            }
        }
    }

    for(int i=0 ; i<board.size() ; i++){
        for(int j=0 ; j<board[0].size() ; j++){
            if(board[i][j]=='O')
                board[i][j] = 'X';
            
            else if(board[i][j]=='*')
                board[i][j] = 'O' ;
        }
    }
    return board ;
    
}

int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    
    vector<vector<char>> b = {{'X','O','X'},{'O','X','O'},{'X','O','X'}} ;
    // vector<vector<char>> b = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}} ;
    print(solve(b)) ;

    return 0 ;
}


/*
"X","O","X"],
"O","X","O"],
"X","O","X"]


*/
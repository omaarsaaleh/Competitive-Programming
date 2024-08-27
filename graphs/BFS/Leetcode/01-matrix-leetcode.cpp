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


// O( n*m * 4^(n*m) )
vector<pair<int,int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}} ;
// int solve(vector<vector<int>>& mat, vector<vector<int>>& ans, int i, int j){
//     if(mat[i][j] == 0) return 0 ;
//     if (ans[i][j] != -1)  return ans[i][j];

//     int a = 1e8 ;

//     for(pair<int,int> d : dir){
//         int n_row = d.first + i  ; 
//         int n_col = d.second + j ;
//         if((n_row > -1  && n_row < mat.size()) && (n_col > -1 && n_col < mat[0].size())){
//             if(mat[n_row][n_col]==0) return 1 ;
//         }
//     }
//     for(pair<int,int> d : dir){
//         int n_row = d.first + i  ; 
//         int n_col = d.second + j ;
//         if((n_row > -1  && n_row < mat.size()) && (n_col > -1 && n_col < mat[0].size())){
//             a = min(a,solve(mat,ans,n_row,n_col)+1) ;
//         }
//     }
    
//     return a ;
// }

// vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//     vector<vector<int>> ans (mat.size(), vector<int> (mat[0].size(),-1));
//     for(int i=0 ;i<mat.size() ; i++){
//         for(int j=0 ; j<mat[0].size() ; j++){
//             ans[i][j] = solve(mat,ans,i,j) ;
//         }
//     }  
//     return ans ;
// }




vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    vector<vector<int>> ans (mat.size(), vector<int> (mat[0].size(),-1));
    queue< pair< pair<int,int> ,int >> q ;
    for(int i=0 ;i<mat.size() ; i++){
        for(int j=0 ; j<mat[0].size() ; j++){
            if(mat[i][j]==0) {
                ans[i][j] = 0 ;
                q.push({{i,j},0}) ;
            }
        }
    }
    // all zero cells = zero
    // all zero adjacents = 1
    // all adjacents of zero adjacents = 2 and so on
    while (!q.empty()){
        pair< pair<int,int> ,int> v = q.front();
        q.pop() ;

        for(pair<int,int> d : dir){
            int n_row = d.first + v.first.first ; 
            int n_col = d.second + v.first.second ;
            if((n_row > -1  && n_row < mat.size()) && (n_col > -1 && n_col < mat[0].size())){
                if(ans[n_row][n_col]==-1){
                    ans[n_row][n_col] = v.second+1 ;
                    q.push({{n_row,n_col},v.second+1});
                }
            }
        }
    }
    
    return ans ;
}


/*
110 110
010 010
111 1*1
*/
int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    
    // vvi mat = {{0,0,0},{0,1,0},{1,1,1}} ;
    vvi mat = {{0,0,0},{0,1,0},{0,0,0}} ;
    print(updateMatrix(mat)) ;

    return 0 ;
}



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


vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    queue<pair<int,int>> q ;
    q.push({sr,sc}) ;
    int allowed_color = image[sr][sc] ; 
    image[sr][sc] = color ;

    vector<vector<bool>> vis(image.size(), vector<bool>(image[0].size(),false)) ;

    while(!q.empty()){
        int row = q.front().first ;
        int col = q.front().second ;
        vis[row][col] = true ;
        q.pop() ;
        
        for(pair<int,int> d : dir){
            int n_row = d.first + row  ; 
            int n_col = d.second + col ;
            if((n_row > -1  && n_row < image.size()) && (n_col > -1 && n_col < image[0].size())){
                if(image[n_row][n_col] == allowed_color && !vis[n_row][n_col]){
                    image[n_row][n_col] = color ;
                    vis[n_row][n_col] = true;
                    q.push({n_row,n_col}) ;
                }
            }
        }
        
    }

    return image ;
}



int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    
    // vvi v = {{1,1,1},{1,1,0},{1,0,1}} ; 
    // print(floodFill(v,1,1,2));

    // vvi v = {{0,0,0},{0,0,0}} ; 
    // print(floodFill(v,0,0,0));

    vvi v = {{0,0,0},{0,0,0}} ; 
    print(floodFill(v,1,0,2)) ;

/*
220
220
r l d u
200
222
*/

    return 0 ;
}





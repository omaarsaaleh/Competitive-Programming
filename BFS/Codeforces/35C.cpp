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
#include <fstream>

 
using namespace std;
#define ll long long 
#define all(x) x.begin(), x.end()
#define for1(n) for (int i = 0; i<n; i++)
#define vi vector<int>
#define vvi vector<vector<int>>
#define eache auto &e

vector<int> dx = {0,0,1,-1} ;
vector<int> dy = {-1,1,0,0} ;

bool isvalid(int &n,int &m, int &x, int &y){
    return ( (x>-1 && x<n) && (y>-1 && y<m) ) ;
}

pair<int,int> bfs(int n, int m, queue< pair<int,int>> &q, vector<vector<bool>> &vis){

    
    pair<int,int> v ;
    

    while(!q.empty()){
        v  = q.front();
        q.pop() ;
        
        for(int i=0 ; i<4 ; i++){
            int x_n = dx[i] + v.first ;
            int y_n = dy[i] + v.second ;

            if( isvalid(n,m,x_n,y_n) && (vis[x_n][y_n]==false)){
                vis[x_n][y_n] = true ;
                q.push(make_pair(x_n,y_n)) ;
                
                
            }
        }
    }

    return v ;

}


int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);


    
    int n,m ; cin >> n >> m ;
    int k ; cin >> k ;
    queue< pair<int,int> > q ;
    vector<vector<bool>> vis(n,vector<bool>(m,false)) ;
    for1(k){
        int a,b ; cin >> a >> b ;
        --a,--b ;
        q.push(make_pair(a,b)) ;
        vis[a][b] = true ;
    }

    pair<int,int> ans = bfs(n,m,q,vis) ;

    cout << ans.first+1 << ' '<< ans.second+1 ;


    return 0 ;
}

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
 
vector < pair<int,int> > moves =
{ {-2,-1}, {-2,1}, {-1,2}, {-1,-2}, {1,2}, {1,-2}, {2,1}, {2,-1}};

bool isvaildmove(int c, int i){
    return (c >= 1 && c <= 8) && (i >= 1 && i <= 8) ; 
}


int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    
    vector< vector< vector< pair<int,int> >>> list(9, vector< vector< pair<int,int> >>(9,  vector< pair<int,int> >()) );


    for(int i=1 ; i<9 ; i++){
        for(int c=1 ; c<9 ; c++){
            for(pair<int,int> move : moves){
                if( isvaildmove(move.first + c, move.second + i ))
                    list[c][i].push_back({move.first + c , move.second + i });
            }
        }
    }


    int t ; cin >> t ;
    while(t--){
        string v, e ; cin >> v >> e ;
        if(v==e){
            cout << "0\n" ;
            continue;
        }
        pair<int,int> st = {v[0]-'a'+1, v[1]-'0' } ;
        pair<int,int> end = {e[0]-'a'+1, e[1]-'0' } ;

        vector<vector<bool>> vis (9, vector<bool>(9)) ;
        vis[st.first][st.second] = true ;
        vector<vector<int>> d (9, vector<int>(9,0)) ;

        queue<pair<int,int>> q ;
        q.push(st) ;

        bool done = false ;
        int ans ;

        while(!q.empty() && !done){
            pair <int,int> vertex = q.front() ;
            q.pop();
            
            for(pair<int,int> j : list[vertex.first][vertex.second]){                      
                if (!vis[j.first][j.second]){ 
                    vis[j.first][j.second] = true ;
                    d[j.first][j.second] = d[vertex.first][vertex.second] + 1 ;

                    if(j==end){
                        done = true ;
                        ans = d[j.first][j.second]  ;
                        break;
                    }
                    q.push(j) ;
                } 
            }
        }
        cout << ans << '\n';
        
    }

    return 0 ;
}

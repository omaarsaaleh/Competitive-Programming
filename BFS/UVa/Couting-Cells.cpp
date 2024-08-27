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
 
const int dx[] = {1,-1,0,0,1,1,-1,-1};
const int dy[] = {0,0,1,-1,1,-1,1,-1};

// https://onlinejudge.org/external/8/871.pdf

bool isValid(int x, int y, int n, int m){
    return (x>-1 && x<n && y>-1 && y<m) ;
}

int bfs(vector<string> graph){
    int n = graph.size(), m = graph.size() ;
    
    vector<vector<bool>> vis(n, vector<bool>(m,false)) ;
    int ans = 0 ;
    
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(graph[i][j]=='1' && vis[i][j]==false){
                vis[i][j] = true ;
                queue<pair<int,int>> q;
                q.push({i,j}) ;
                int c = 1 ;
                while(q.empty()==false){
                    pair<int,int> v = q.front() ;
                    q.pop() ;
                    for(int k=0 ; k<8 ; k++){
                        int x_n = v.first + dx[k]; 
                        int y_n = v.second + dy[k];

                        if(isValid(x_n,y_n,n,m)==false) continue;

                        if(graph[x_n][y_n]=='1' && vis[x_n][y_n]==false){
                            q.push({x_n,y_n}) ;
                            vis[x_n][y_n] = true ;
                            c++ ;
                        } 
                    }
                }
                ans = max(ans,c) ;
            }
        }
    }

    return ans ;
}

int main () {
    // std::ios_base::sync_with_stdio(0) ;
    // std::cin.tie(0); std::cout.tie(0);
    
    int t ; cin >> t ;
    bool f = 1 ;
    string e ; getline(cin,e);
    getline(cin,e);
    while (t--){
        
        vector< string > graph ;
        string s ; 
        while (getline(cin,s)){
            if(s.empty()) break;
            graph.push_back(s);
            
        }
        
        cout << bfs(graph) <<'\n' ;
        if(t) cout << '\n' ;
        
    }
    


    

    return 0 ;
}

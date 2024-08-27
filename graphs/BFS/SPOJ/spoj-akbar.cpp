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
 


int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    
    int t ; cin >> t ;
    while(t--){
        int n, r, m ;
        cin >> n >> r >> m ;

        vvi list(n+1) ;

        for1(r){
            int v1, v2 ;
            cin >> v1 >> v2 ;
            list[v1].push_back(v2);
            list[v2].push_back(v1);
        }


        vector<bool> vis(n+1,false) ;
        vector<int> solider(n+1,0);
        bool overlap = false ;

        for1(m){
            int v, plength ;
            cin >> v >> plength ;
            
            if( vis[v]) {overlap = true ; continue;;}

            queue<pair<int,int>> q ;
            q.push({v,0}) ;

            vis[v] = true  ;
            solider[v] = v ;


            while(!q.empty() && !overlap){
                pair <int,int> vertex = q.front() ;
                q.pop();

                if(vertex.second+1 <= plength){ // respect the solider power  
                    
                    for(int j : list[vertex.first]){                      
                        if (vis[j]){ // if already assigned to a solider
                            if(solider[j]!= v){ // if the current solider is not the same solider which was assigned to the city
                                overlap = true ;
                                break;
                            }
                        } 
                        else{
                            vis[j] = true ;
                            solider[j] = v ;
                            q.push({j,vertex.second+1}) ;
                        }   
                    }

                }
                
            }
        }
        
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                overlap = true;
                break;
            }
        }
        
        
        cout << (overlap? "No" : "Yes") << '\n' ;
    }
     

    return 0 ;
}

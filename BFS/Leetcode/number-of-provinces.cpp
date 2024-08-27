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
 
int findCircleNum(vector<vector<int>>& isConnected) {
    int sz = isConnected.size() ;
    vector<vector<int>> list(sz) ;
    for(int i=0; i<sz ; i++)
        for(int j=0 ; j<sz ; j++)
            if(i!=j && isConnected[i][j]){
                list[i].push_back(j);
            }
        

    vector<bool> vis(sz,false) ;
    int vis_sz = 0 ;
    int last_nonvis = 0 ; 
    int groups = 0 ;
    while(vis_sz != sz){
        queue<int> q ;
        for(int i=last_nonvis ; i<sz ; i++){
            if(!vis[i]){
                q.push(i);
                break;
            }
        }
        while(!q.empty()){
            int city = q.front() ;
            q.pop();
            vis[city] = true ;
            vis_sz++;

            for(int adj_city : list[city]){
                if(!vis[adj_city]){
                    vis[adj_city] = true ;
                    q.push(adj_city) ;
                }
            }
        }
        groups++ ;
    }
    return groups ;


}

/*
[1,0,0,1],
[0,1,1,0],
[0,1,1,1],
[1,0,1,1]

0 3
1 2
2 3
 
0 3 2 1 



*/

int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    
    vvi v = {
    {1,0,0,1},
    {0,1,1,0},
    {0,1,1,1},
    {1,0,1,1}
    };

    cout << findCircleNum(v) ;



    return 0 ;
}



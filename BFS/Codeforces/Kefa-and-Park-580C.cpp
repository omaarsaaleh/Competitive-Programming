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
 

int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    
    int n,m ; cin >> n >> m ;
    vector<bool> cat(n+1);
    for1(n){
        int x ; cin >> x ;
        cat[i+1] = (bool)x ;
    }
    vector< vector<int> > list(n+1,vector<int>()) ;
    for1(n-1){
        int v1,v2 ;
        cin >> v1 >> v2 ;
        list[v1].push_back(v2);
        list[v2].push_back(v1);
    }


    queue<pair<int,int>> q ;
    q.push({1,cat[1]}) ; // vertex_num, cats
    int rest = 0 ;
    vector<bool> vis(n+1,false);

    while(!q.empty()){
        pair<int,int> v = q.front() ;
        q.pop();
        vis[v.first] = true;


        if(list[v.first].size()==1 && vis[list[v.first][0]]) rest++;
        else{    
            for(int child : list[v.first]){
                if(!vis[child]){    
                    if(cat[child]){
                        if( 1+v.second <= m) q.push({child,1+v.second}) ;
                    }
                    else q.push({child,0}) ;
                }
                
            }
        }
    }

    cout << rest ;

    return 0 ;
}


/*
12 3
1 0 1 0 1 1 1 1 0 0 0 0

6 7
12 1
9 7
1 4
10 7
7 1
11 8
5 1
3 7
5 8
4 2



*/
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
 
// smaller - or *
// bigger - only

pair<int,int> get_next_step(int n){
    return make_pair(n-1,n*2) ;
} 

int bfs(int a, int b){

    if(a>b) return a-b ;


    // a<b
    // max number will be 2*b-1

    queue<pair<int,int>> q;

    q.push(make_pair(a,0));
    
    vector<bool> vis(2*b,false) ;

    while (!q.empty()){
        pair <int,int> v = q.front() ;
        q.pop() ;
        vis[v.first] = true ;

        if(v.first==b) return v.second ;

        pair<int,int> nx = get_next_step(v.first) ;
        if(nx.first>0 && vis[nx.first]==false) q.push(make_pair(nx.first,v.second+1)) ;
        if(v.first<b && vis[nx.second]==false) q.push(make_pair(nx.second,v.second+1)) ;

    }
    return 0 ;
}


int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    
    
    int a,b; cin >> a >> b ;

    cout << bfs(a,b) ;

    return 0 ;
}

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
#define pii pair<int,int>
#define eache auto &e
 
template<class t>
void print(const t a) {cout << a << '\n';}
template<class t>
void print(const vector<t>&v){for(t e:v){cout<<e<<' ';}cout<<'\n';}
template<class t>
void print(const vector<vector<t>>&v) {for(vector<t> e:v)print(e);}

// Codeforces 606D
// Lazy Student

struct DSU{
    vector<int> parent ;
    vector<int> sz ;
    DSU(int n) {
        parent.resize(n+1);
        sz.resize(n+1, 1);
        for(int i = 1; i <= n; i++)
            parent[i] = i;
    }
    
    int Find(int x){
        if ( parent[x] == x) return x;
        return parent[x] = Find( parent[x] );
    }

    bool is_connected(  int u, int v){
        return Find(u) == Find(v) ;
    }
    
    bool Union(int u, int v){
        int par1 = Find(u), par2 = Find(v);	
        if(par1 == par2){
            return false ;
        }

        if(sz[par1] > sz[par2]) 
            swap(par1, par2);
        sz[par2] += sz[par1];
        sz[par1] = 0;
        parent[par1] = par2;
        return true ;
    }


};

struct Edge {
    int u, v, weight;
    Edge(int a, int b, int c) : u(a),v(b),weight(c){}
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
    bool operator>(Edge const& other) {
        return weight > other.weight;
    }
};

int summation(int n){
    return (n+1)*0.5*n ;
}

vector<pii> MST(int &n, vector< pair< pair<int,bool>,int > >  &edges){
    
    sort(edges.begin(), edges.end(), [](const pair<pair<int, bool>, int>& a, const pair<pair<int, bool>, int>& b) {
        if (a.first.first == b.first.first)
            return a.first.second > b.first.second; 
        
        return a.first.first < b.first.first; 
    });
    int used = 0 ;
    int a = 1, b = 2;
    int sz = 1 ;
    
    vector<int> skip(n+1);
    iota(all(skip),2) ;
    int i = 1 ;
    
    vector<pii> ans(edges.size()) ;
    bool cant = false ;
    for (auto e : edges) {
        if(e.first.second==true){
            sz++ ;
            ans[e.second] = {a++,b++};
        }
        else{
            if(sz<n && summation(sz-2)-used < 1){cant=true; break;}
            used ++ ;
            if(skip[i]>sz)
                i++;
            if(i>sz || skip[i]>sz) i=1;
             
            ans[e.second] = {i,skip[i]++} ;
        }
       
    }
    return (cant? vector<pii>() : ans) ;
}


int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);

    int n, m ; cin >> n >> m ;
    vector< pair< pair<int,bool>,int > >  edges(m) ;
    for1(m){
        edges[i].second = i ;
        cin >> edges[i].first.first >> edges[i].first.second ;
    }
    vector<pii> ans = MST(n, edges);

    if(ans.empty()) cout << "-1";
    else{
        for(auto p : ans)
            cout << p.first << ' ' << p.second << '\n';
    }



    return 0 ;
}




/*

10 15

0 1
1 1
2 0
3 1
4 0
5 0
6 1
7 0
8 0
9 0
10 1
11 1
12 1
13 1
14 1


*/
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
#include <stack>
 
 
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

// Anansi's Cobweb
// https://acm.timus.ru/problem.aspx?space=1&num=1671

struct DSU{
    vector<int> parent ;
    vector<int> sz ;
    int comp ; 
    DSU(int n) : comp(n) {
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
        comp-- ;
        sz[par2] += sz[par1];
        sz[par1] = 0;
        parent[par1] = par2;
        return true ;
    }
};

int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    
    int n,m ; cin >> n >> m ;
    vector< pair<pii,bool> > edges(m) ;
    for1(m){
        int a,b ; cin >> a >> b ;
        edges[i] = {{a,b},true};
    }
    int de ; cin >> de ;
    stack<int> q ;
    for1(de){
        int c ; cin >> c ;
        c-- ;
        q.emplace(c) ;
        edges[c].second = false ;
    }
    DSU d(n);
    for1(m){
        if(edges[i].second)
            d.Union(edges[i].first.first,edges[i].first.second);
    }

    stack<int> ans ;
    for1 (de){
        ans.push( d.comp)  ;
        int v = q.top() ; q.pop();
        d.Union(edges[v].first.first,edges[v].first.second);
    }

    for1(de){
        cout << ans.top() << ' '; ans.pop() ;
    }
    
    
    

    return 0 ;
}



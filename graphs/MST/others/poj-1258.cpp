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

// POJ 1258

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

int MST(int &n, vector<Edge> &edges){
    
    DSU d(n) ;    

    sort(edges.begin(), edges.end());
    int cost = 0 ;
    for (Edge e : edges) {
        if (d.is_connected(e.u,e.v)==false) {
            cost += e.weight ;
            d.Union(e.u, e.v);
        }
    }
    return cost ;
}


int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    string _ ;

    int n ; 
    while (cin >> n ){
        vector<Edge> edges ;
            
        for1(n){
            for2(n){
                int a ; cin >> a ;
                if(j>i)
                    edges.push_back(Edge(i+1,j+1,a));
            }
        }     
            
        cout << MST(n,edges) << '\n';
    }
    
    


    return 0 ;
}




/*

*/
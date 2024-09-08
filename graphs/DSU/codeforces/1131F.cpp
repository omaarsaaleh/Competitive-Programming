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
#define for1(n) for (int i = 1; i<=n; i++)
#define for2(n) for (int j = 1; j<=n; j++)
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

// Codeforces 1131F
// Asya And Kittens

struct DSU{
    vector<int> parent, sz ;
    vvi components ;
    DSU(int n) : components(n+1,vector<int>()){
        parent.resize(n+1);
        sz.resize(n+1, 1);
        for(int i = 1; i <= n; i++)
            parent[i] = i;    
    }
    
    int Find(int x){
        if ( parent[x] == x) return x;
        return parent[x] = Find( parent[x] );
    }
    
    void Union(int u, int v){
        int par1 = Find(u), par2 = Find(v);	
        if(par1 == par2) return;

        if(sz[par1] > sz[par2]) 
            swap(par1, par2);
        sz[par2] += sz[par1];
        for(int i=components[par1].size()-1 ; i>=0 ; i--){
            components[par2].push_back(components[par1][i]);
            components[par1].pop_back() ;
        }
        sz[par1] = 0;
        parent[par1] = par2;
    }
    void solve(){
        print(components[Find(1)]) ;
    }

};

int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    
    int n ; cin >> n ;
    DSU d(n) ;
    int m = n-1;
    for1(m){
        int a,b ; cin >> a >> b ;
        d.Union(a,b) ;
    }

    d.solve() ;

    return 0 ;
}



// 1 component = 0
// 2 component = 1
// 3 component = 2
// at most   min(comp1,comp2)-1
// 

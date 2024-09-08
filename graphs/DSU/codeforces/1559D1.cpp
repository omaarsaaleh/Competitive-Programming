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

// Codeforces 1559D1
// Mocha and Diana (Easy Version)

struct DSU{
    vector<int> parent, sz ;
    int components ;
    DSU(int n) : components(n){
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
        components--;
        sz[par2] += sz[par1];
        sz[par1] = 0;
        parent[par1] = par2;
    }

    int get_components() const{return this->components;}
    
    bool is_connected(int u, int v)  { return this->Find(u)==this->Find(v) ;}

};

int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    

    int n,m1,m2 ; cin >> n >> m1 >> m2 ;
    DSU d1(n);
    DSU d2(n);
    for1(m1){
        int a,b ; cin >> a >> b ;
        d1.Union(a,b) ;
    }
    for1(m2){
        int a,b ; cin >> a >> b ;
        d2.Union(a,b) ;
    }

    vector< pii > ans ;

    if(d1.get_components()>1 && d2.get_components()>1){    
        for1(n){
            for2(n){
                if(d1.is_connected(i,j)==false && d2.is_connected(i,j)==false){
                    d1.Union(i,j);
                    d2.Union(i,j);
                    ans.push_back({i,j}) ;
                }
            }
        }
    }

    cout << ans.size() << '\n' ;
    for(pii p : ans){cout << p.first << ' ' << p.second << '\n' ;}



    return 0 ;
}



// 1 component = 0
// 2 component = 1
// 3 component = 2
// at most   min(comp1,comp2)-1
// 

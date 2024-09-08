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

// Codeforces 25D
// Roads not only in Berland

struct DSU{
    vector<int> parent, sz ;
    vector<pii> useless ;
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
    
    void Union(int u, int v){
        int par1 = Find(u), par2 = Find(v);	
        
        if(par1 == par2) {useless.emplace_back(u,v) ;return;}

        if(sz[par1] > sz[par2]) 
            swap(par1, par2);
        sz[par2] += sz[par1];
        sz[par1] = 0;
        parent[par1] = par2;
    }

    void solve(){
        cout << useless.size() << '\n';
        int n = parent.size() ;
        int i = 1 ;
        for(pii p : useless){
            cout << p.first << ' ' << p.second << ' ';
            for2(2){
                for(; i<n ; i++){
                    if(sz[i]){
                        cout << i << ' ';
                        if(j==0) i++ ;
                        break;
                    }
                }
            }
            cout << '\n';
        }
    }
    
    bool is_connected(int u, int v)  { return this->Find(u)==this->Find(v) ;}

};


int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    
    int n,m ; cin >> n ;
    m = n-1 ;
    DSU d(n) ;
    
    for1(m){
        int a,b; cin >> a >> b  ;
        d.Union(a,b) ;
    }

    d.solve();


    return 0 ;
}
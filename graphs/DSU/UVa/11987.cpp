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

// Almost Union-Find
// https://onlinejudge.org/external/119/11987.pdf

template<class t>
void print(const t a) {cout << a << '\n';}
template<class t>
void print(const vector<t>&v){for(t e:v){cout<<e<<' ';}cout<<'\n';}
template<class t>
void print(const vector<vector<t>>&v) {for(vector<t> e:v)print(e);}



struct DSU{
    vector<int> parent, sz, sum ;
    
// initially every element is linked to a parent
// from n+1 to 2*n, so that no other element would be linked
// to each other (will be linked to vertices (n+1 to 2*n)),
// so we could move vertices 1 to n as we would like

    DSU(int n) {
        parent.resize(2*n+1);
        sum.resize(2*n+1);
        sz.resize(2*n+1, 1);
        for ( int i = 1, j = n + 1; i <= n; i++, j++ ) {
            parent[i] = j;
            parent[j] = j;
            sum[j] = i;
        }
    }
    
    int Find(int x){
        if ( parent[x] == x) return x;
        return parent[x] = Find( parent[x] );
    }

    bool Union(int u, int v){
        int par1 = Find(u), par2 = Find(v) ;	
        if(par1 == par2)
            return false ;
        
		
        if(sz[par1] > sz[par2]) 
            swap(par1, par2), swap(u,v);
        
		sz[par2] += sz[par1];
        sum[par2] += sum[par1];
        
        parent[par1] = par2;
		sum[par1] = 0;
        sz[par1] = 0;
		
        return true ;
    }

	bool move(int u, int v){ // move u to v
        int par1 = Find(u), par2 = Find(v) ;	
        if(par1 == par2)
            return false ;
		
        sz[par2]++, sz[par1]--;
        sum[par2]+=u, sum[par1]-=u;

        parent[u] = par2 ;

        return true;
	}

    void op3(int v){
        int p = Find(v) ;
        cout << sz[p] << ' ' << sum[p] << '\n' ;
    }
   

};


int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    
    int n ; 
    while(cin >> n){
        int m ; cin >> m ;
        DSU d(n) ;

        for1(m){
            int cmd ; cin >> cmd ;
            if(cmd==1){
                int p,q ; cin >> p >> q ;
                d.Union(p,q) ;
            }
            else if(cmd==2){
                int p,q ; cin >> p >> q ;
                d.move(p,q) ;
            }
            else{
                int p ; cin >> p ;
                d.op3(p) ;
            }
        }
    }
    return 0 ;
}




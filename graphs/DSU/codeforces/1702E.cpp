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

// Codeforces 1702E
// Split Into Two Sets

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
    
    bool solve(){
        for(int s : sz){
            if(s%2) return false ;
        }
        return true ;
    }


};




int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    
 
    int t ; cin >> t ;
    while (t--){
        int n ; cin >> n ;
        bool cant = false ;
        DSU d(n) ;
        vector<int> freq(n+1,0) ;

        for1(n){
            int a,b ; cin >> a >> b ;
            if( ++freq[a]>2 || ++freq[b]>2) cant = true ;
            d.Union(a,b) ;
        }
        if(cant){cout << "NO\n" ; continue;}

        cout << (d.solve()? "YES" : "NO") << '\n' ;
    }
    return 0 ;
}




/*

1
6
1 2
3 4
1 5
2 6
4 5
3 6
YES



12
45
36

15
34
26

*/
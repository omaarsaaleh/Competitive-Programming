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

// Friends
// https://onlinejudge.org/external/106/p10608.pdf

struct DSU{
    vector<int> parent, sz ;
    int maxSize ;
    DSU(int n) : maxSize(1){
        parent = sz = vector<int> (n + 1, 0);
		for(int i = 1; i <= n; i++)
			parent[i] = i, sz[i] = 1;
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
        maxSize = max(maxSize, sz[par2]);
        sz[par1] = 0;
        parent[par1] = par2;
    }

    int get_largest_group() const{
        return this->maxSize;
    }


};

int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    
    int t ; cin >> t; 
    while(t--){
        int n,m ; cin >> n >> m ;
        DSU d(n);
        for1(m){
            int a,b ; cin >> a >> b ;
            d.Union(a,b) ;
        }
        cout << d.get_largest_group() << '\n' ;
    }


    return 0 ;
}





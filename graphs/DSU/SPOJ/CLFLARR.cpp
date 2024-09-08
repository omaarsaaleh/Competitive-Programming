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

struct DSU{
    vector<int> parent;
    DSU(int n) {
        parent.resize(n+2);
        for(int i = 1; i <= n+1; i++)
            parent[i] = i;
    }
    
    int Find(int x){
        if ( parent[x] == x) return x;
        return parent[x] = Find( parent[x] );
    }
    
    void Union(int u, int v){
        parent[u] = Find(v); // u is done, point to the next
    }
};

struct Paint{
    int st, end , color ;
    Paint(int a, int b, int c) : st(a), end(b), color(c) {}
};

int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    
    int n,q ; cin >> n >> q ;
    vector<Paint> paints ;
    for1(q){
        int a,b,c ; cin >> a >> b >> c ;
        paints.push_back(Paint(a,b,c));
    }
 

    DSU d(n) ;
    vector<int> ans(n+1) ;
    for(int i=q-1 ; i>-1 ; i--){
        Paint p = paints[i];
        int st = d.Find(p.st);
        while(st<=p.end){
            ans[st] = p.color ;
            d.Union(st,st+1); // point to the upcoming element
            st = d.parent[st] ; // find the first uncolored element
        }
    }

    for(int i = 1; i <= n; i++) cout << ans[i] << '\n' ;

    return 0 ;
}





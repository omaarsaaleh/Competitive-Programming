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

// Codeforces 939D
// Love Rescue

struct DSU{
    vector<int> parent ;
    DSU() {
        parent = vector<int>(26) ;
		for(int i = 0; i < 26; i++)
			parent[i] = i;
    }
    
    int Find(int x){
        if ( parent[x] == x) return x;
        return parent[x] = Find( parent[x] );
    }

    bool is_connected(  int u, int v){
        return Find(u) == Find(v) ;
    }
    
    void Union(int u, int v){
        int par1 = Find(u), par2 = Find(v);	
        if(par1 == par2) return;

        parent[par1] = par2;
    }


};

int main () {
    std::ios_base::sync_with_stdio(0) ;
    std::cin.tie(0); std::cout.tie(0);
    
 
    int m ; cin >> m ;
    string s1,s2 ; cin >> s1 >> s2 ;
    DSU d; 
    vector<pair<char,char>> ans ;
    for1(m){
        if( d.is_connected(s1[i]-'a', s2[i]-'a')==false ){
            d.Union(s1[i]-'a', s2[i]-'a') ;
            ans.push_back({s1[i], s2[i]}) ;
        }
    }
    cout << ans.size()  << '\n';
    for(pair<char,char> p : ans )
        cout << p.first << ' ' << p.second << '\n' ;



    return 0 ;
}




/*

*/
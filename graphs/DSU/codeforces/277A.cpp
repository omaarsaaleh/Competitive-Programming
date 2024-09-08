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

// Codeforces 277A
// Learning Languages

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
    
    int e,l ; cin >> e >> l ;
    vvi langs_emp(l+1, vector<int>()) ;
    DSU d(e) ;
    int Illiterate = 0 ;
    for1(e){
        int num ; cin >> num ;
        if(num==0) Illiterate++ ;

        for2(num){
            int lang ; cin >> lang ;
            for(int emp : langs_emp[lang])
                d.Union(emp,i+1) ;
            langs_emp[lang].push_back(i+1) ;     
        }
    }
    cout << (Illiterate==e? e : d.get_components()-1)  ;
    


    return 0 ;
}





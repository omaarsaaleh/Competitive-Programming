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
#include <fstream>

using namespace std;
#define ll long long 
#define all(x) x.begin(), x.end()
#define for1(n) for (int i = 0; i<n; i++)
#define vi vector<int>
#define vvi vector<vector<int>>
#define eache auto &e

// longest path DFS



int dfs(int v, vector<vector<int>>& adj, vector<bool>& vis, int& diameter) {
    
    vis[v] = true;
    int max1 = 0, max2 = 0;

    // get greatest two paths for each node
    for (int u : adj[v]) {
        if (vis[u]== false){
            int pathLen = dfs(u, adj, vis, diameter);
            if (pathLen > max1) {
                max2 = max1;
                max1 = pathLen;
            } 
            else if (pathLen > max2) 
                max2 = pathLen;
            
        }
    }

    // update each time the diameter with the sum of the greatest two pathes if bigger
    diameter = max(diameter, max1 + max2);

    return max1 + 1;
}


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int n,m ; cin >> n ;
    m = n-1 ;
    vvi adj(n) ;

    for1(m){
        int a,b ; cin >> a >> b ;
        --a,--b ;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> vis(n, false);
    int diameter = 0;

    dfs(0, adj, vis, diameter);

    cout << diameter ;


    
    
    return 0;
}

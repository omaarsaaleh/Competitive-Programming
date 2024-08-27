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

// longest path BFS


pair<int, int> get_farthest_node(int start, vector<vector<int>>& adj) {
    
    vector<int> dist(adj.size(), -1);    
    dist[start] = 0;

    queue<int> q;
    q.push(start);

    int farthestNode = start;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
                if (dist[neighbor] > dist[farthestNode]) 
                    farthestNode = neighbor;
                
            }
        }
    }

    return {farthestNode, dist[farthestNode]};
}

int get_diameter(vector<vector<int>>& adj) {
    pair<int, int> firstBFS = get_farthest_node(0, adj);
    pair<int, int> secondBFS = get_farthest_node(firstBFS.first, adj);
    return secondBFS.second;
}


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int n,m ; cin >> n >> m ;

    vvi adj(n) ;

    for1(m){
        int a,b ; cin >> a >> b ;
        --a,--b ;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    
    cout << get_diameter(adj) ;

    return 0;
}

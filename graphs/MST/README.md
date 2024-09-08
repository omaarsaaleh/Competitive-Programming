# MST

A subtree of a weighted undirected graph which connects all vertices (i.e. it is a spanning tree) and has the least possible total weight.

A minimum spanning tree of a graph is unique, if the weight of all the edges are distinct. 
Otherwise, there may be multiple minimum spanning trees.

# **Kruskal's algorithm**

1. Sort edges by weight (in non-decreasing order).
2. Loop over the edges and keep picking the edges that does not form a cycle until all vertices are connected

## Proof of correctness

Let’s assume that this is the MST and it does not contain the minimum weight edge 5–6.

![image](https://github.com/user-attachments/assets/563b5479-6f99-4c80-a60f-2e02f8816dc7)

So from our assumption weight(edge 5-6) < weight(any other edge)
However that’s contradiction because that’s mean that we could simply replace edge 5-6 with edge 2-4 for example and get a ST with lower cost.

 

![image](https://github.com/user-attachments/assets/080d7477-eda8-47c6-920a-c56c17505beb)

It is always optimal to include the minimum weight edge in the tree (if possible) to produce a minimum spanning tree.

## Naive **implementation**

$O(MlogN + N^2)$

```cpp
struct Edge {
	int u, v, weight;
	bool operator<(Edge const& other) {
		return weight < other.weight;
	}
};

vector<Edge> MST(int &n, vector<Edge> &edges){
    // give every tree an id
    vector<int> tree_id(n);
    // at first every vertex is a tree by its self
    for (int i = 0; i < n; i++)
        tree_id[i] = i;

    vector<Edge> result;

    sort(edges.begin(), edges.end());

    for (Edge e : edges) {
    // if the id of the tree of each edge is not equal 
    // i.e. they are in different trees
        if (tree_id[e.u] != tree_id[e.v]) {
            result.push_back(e);
        
            // select one tree and append its id to every other edge
            // in the second tree
            
            int old_id = tree_id[e.u], new_id = tree_id[e.v];
            for (int i = 0; i < n; i++) {
                if (tree_id[i] == old_id)
                    tree_id[i] = new_id;
            }
        }
    }
    return result ;
}

```

## **Disjoint Set Union Implementation**

$O(MlogN)$

```cpp
struct DSU{
    vector<int> parent, sz ;
    DSU(int n) : comp(n) {
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
        sz[par2] += sz[par1];
        sz[par1] = 0;
        parent[par1] = par2;
    }
    
    bool is_connected(int u, int v)  { return this->Find(u)==this->Find(v) ;}

};

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

vector<Edge> MST(int &n, vector<Edge> &edges){
    
    DSU d(n) ;    
    vector<Edge> result;

    sort(edges.begin(), edges.end());

    for (Edge e : edges) {
        if (d.is_connected(e.u,e.v)==false) {
            result.push_back(e);
            d.Union(e.u, e.v);
        }
    }
    return result ;
}

```

# **Prim's algorithm**

Resembles Dijkstra’s algorithm. The difference is that Dijkstra’s algorithm always selects an edge whose distance from the starting node is
minimum, but Prim’s algorithm simply selects the minimum weight edge that
adds a new node to the tree.

1. Start with an arbitary vertex
2. Traverse the tree and Keep picking the edge with the **least weight that connects the current tree with any vertex oustide.**

## **Trivial implementation**

$o(nm)$
For sparse graph $o(n^2)$, for dense graph $o(n^3)$

```cpp
struct Edge {
    int u, v, weight;
    Edge(int u, int v ,int w): u(u), v(v), weight(w) {}
    bool operator<(Edge const& other) const {
        return weight < other.weight;
    }
};

// 1-Based, assumes that the graph is connected
vector<Edge> MST(int &n, vector<Edge> &edges){
    int m = edges.size() ;

    vector<bool> vis(n+1, false);
    vis[1] = true ;
    
    vector<Edge> result ;

    // loop n-1 times to get the n-1 edges
    for (int i = 1; i < n ; i++) {
        int minWeight = INT_MAX;
        Edge e(-1,-1,-1) ;

        for (int j = 0; j < m; j++) {
            if ((vis[edges[j].u] != vis[edges[j].v])) { // one visited and one unvisited
                if (edges[j].weight < minWeight) {
                    minWeight = edges[j].weight;
                    e = edges[j];
                }
            }
        }
        vis[e.u] = true;
        vis[e.v] = true;
        result.push_back(e) ;

    }
    return result ;
}
```

## Priority Queue

$O(n^2logm)$

For sparse graph and dense graph $o(n^2logn)$

```cpp
struct Edge {
    int u, v, weight;
    Edge(int u, int v ,int w): u(u), v(v), weight(w) {}
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

struct EdgeMinHeapCompare {
    bool operator()(Edge const& e1, Edge const& e2) {
        return e1.weight > e2.weight; 
    }
};

vector<Edge> Prim_MST(int n, vector<vector<int>> graph) {
    vector<Edge> result; 
    vector<bool> vis(n+1, false); 
    priority_queue<Edge, vector<Edge>, EdgeMinHeapCompare> pq; // Min-heap priority queue

    vis[1] = true;
    for (int v = 2; v <= n; v++) {
        if (graph[1][v] != 0 && !vis[v]) 
            pq.push(Edge(1, v, graph[1][v]));    
    }

    for (int k=1 ;k<n ; k++) {
        Edge edge = pq.top();
        pq.pop();

        int u = edge.u;
        int v = edge.v;
        int weight = edge.weight;

        if (vis[v]) continue; 
        vis[v] = true;
        result.push_back(edge);

        for (int i = 1; i <= n; i++) {
            if (graph[v][i] != 0 && !vis[i]) 
                pq.push(Edge(v, i, graph[v][i]));
            
        }
    }

    return result;
}

```

References :

https://cp-algorithms.com/graph/mst_kruskal.html  
https://cp-algorithms.com/graph/mst_kruskal_with_dsu.html    
https://usaco.guide/CPH.pdf#page=152  
https://cp-algorithms.com/graph/mst_prim.html

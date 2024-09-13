# Dijkstra Algorithm
Dijkstra's algorithm finds the shortest path from a given source node to every other node.

The graph can be either directed or undirected. However, the algorithm requires that there are no negative weight edges in the graph.

# Algorithm

1. Initially, the shortest distances of all nodes are set to infinity except of the starting node = 0.
2. Perform n iternations
    1. Select the nearest **unvisited** node to the source, i.e. the node
    whose distance is the smallest and mark it as visited. Let it be u.
    2. Relax all the outgoing edges from node u.

Relaxation is a core concept in Dijkstra’s algorithm that involves
updating the shortest known distance to a node.

# Example

1. The Start at Node 0

Assign the shortest distances of all nodes to infinity except of the starting node to 0.
Mark Node 0 as visited.  
Relax all the outgoing nodes from Node 0.  
Nodes (1,3,4).

![0](https://github.com/user-attachments/assets/a47d5a34-5f5d-4514-b8e1-ec551c336b7b)

2. Pick the unvisited node with the shortest distance which is Node 1.

Mark Node 1 as visited.  
Relax all the outgoing nodes from Node 1.  
Node (2).

![1](https://github.com/user-attachments/assets/967d2c6c-971a-45cf-8091-f32ccedd5104)

3. Pick the unvisited node with the shortest distance which is Node 2.

Mark Node 2 as visited.  
Relax all the outgoing nodes from Node 2.  
Node (3).

![2](https://github.com/user-attachments/assets/3f30c964-212f-441d-8fb3-b32f265af6aa)

4. Pick the unvisited node with the shortest distance which is Node 3.

Mark Node 3 as visited.  
Relax all the outgoing nodes from Node 3.  
NO NODES.

![3](https://github.com/user-attachments/assets/4cd9e099-2cfd-458d-8533-8b269dcc82ff)

5. Pick the unvisited node with the shortest distance which is Node 4.

Mark Node 4 as visited.  
Relax all the outgoing nodes from Node 4.  
NO NODES.

![4](https://github.com/user-attachments/assets/2533c755-6b50-4dad-a53d-93edd8d9a52a)

Final Result.

![6](https://github.com/user-attachments/assets/bd5fe198-3cbd-4693-934a-bf74c3b8d259)

# Naive Implementation

$O(v^2 + e)$.

$O(v^2)$ for sparse and dense graphs. Optimal for dense but not sparse.

```cpp
vector<int> dis ;
vector<int> p ;
// 1-based
void dijkstra(int s, vvpii &adj) {
    int n = adj.size()-1;
    dis.assign(n+1, INT_MAX);
    p.assign(n+1, -1);
    vector<bool> vis(n+1, false);

    dis[s] = 0;
    for (int i = 1; i <= n; i++) {
        int v = -1;
        // pick the edge with shortest distance to reach
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && (v == -1 || dis[j] < dis[v]))
                v = j; 
        }
				
        // if there are no more reachable nodes from the starting node s
        // omit if the graph is connect
        if (dis[v] == INT_MAX) 
            break;
    
        vis[v] = true;
        // relaxation
        for (pii edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (dis[v] + len < dis[to]) {
                dis[to] = dis[v] + len;
                p[to] = v;
            }
        }
    }
}
```

# Optimal Implementation

**Outdated nodes** refer to nodes in the data structure (either a set or a priority queue) whose distance value is no longer accurate due to finding a shorter path after they were added.

## Set

$O(elogv)$.

$O(v^2log(v))$ for dense graphs and $o(vlog(v))$ sparse graphs. 

Use a set and once you find a better route to a node, delete the outdated version and insert the new one to the set.

```cpp
vector<int> dis ;
vector<int> p ;
// 1-based
void dijkstra_set(vvpii &adj, int s){
    int n = adj.size()-1 ;
    dis.assign(n+1, INT_MAX); 
    p.assign(n+1, -1);
    dis[s] = 0;
    set<pair<int, int>> st;
    st.insert({0,s});
    while (!st.empty()) {

        int v = st.begin()->second; 
        st.erase(st.begin());
        
        for (auto u : adj[v]) {
            int to = u.first, len = u.second;
            if (dis[v] + len < dis[to]) {
                st.erase({dis[to],to});
                dis[to] = dis[v] + len;
                st.insert({dis[to],to});
                p[to] = v;
            }
        }
    }
}
```

## Priority Queue

$O(v  log(v) + e).$

$O(v^2)$ for dense graphs and $o(vlog(v))$ sparse graphs. 

Uses a priority queue (min-heap) to efficiently get the node with the smallest distance.
Priority queue in C++ does not support deletion so the updated node is simply inserted into the priority queue without removing the outdated one.

That’s not a problem as the logic will ignore the outdated ones.
But we can optimize it to avoid unnecessary iterations. 

By checking if the current node is in its optimum distance using the condition: **`if(d!=dis[v]) continue;`** 

Another approach is to maintain a **`vis[]`** array to track visited nodes. And only process a node the first time it's visited (since the first visit will always correspond to the shortest distance), we can efficiently skip outdated nodes.

```cpp
vector<int> dis ;
vector<int> p ;
// 1-based
void dijkstra(vvpii &adj, int s){
    int n = adj.size()-1 ;
    dis.assign(n+1, INT_MAX); 
    p.assign(n+1, -1);
    dis[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0,s});
    while (!q.empty()) {
        auto [v,d] = q.top(); 
        q.pop();
				
        // skip outdated nodes
        if(d!=dis[v]) continue;
        
        for (auto u : adj[v]) {
            int to = u.first, len = u.second;
            if (dis[v] + len < dis[to]) {
                dis[to] = dis[v] + len;
                q.push({dis[to],to});
                p[to] = v;
            }
        }
    }
}

```

# Restoring The Path

Traverse from the end until reaching the start, then reverse.

$o(v)$

```cpp
vector<int> restore_path(int st, int end, vector<int> &p) {
    
    vector<int> path;
    for (int v = end; v != st; v = p[v])
        path.push_back(v);
    path.push_back(st);

    reverse(path.begin(), path.end());
    return path;
}
```

References :

https://usaco.guide/gold/shortest-paths?lang=cpp

https://cp-algorithms.com/graph/dijkstra.html

https://cp-algorithms.com/graph/dijkstra_sparse.html

# Extras

## 0-1 BFS

an algorithm used for finding the shortest path in a graph where the edges have weights that are either 0 or 1 in $O( v+e )$

Uses a deque to keep track of the nodes to be processed.  
Nodes connected via an edge with weight 0 are placed at the front of the deque.  
Nodes connected via an edge with weight 1 are placed at the back of the deque.  

This Maintains the Order as nodes in the deque have distances that differ by at most one unit. 

### But Why?

Suppose, for contradiction, that there is a vertex $u$ in the deque with a distance $d[u]$ such that: 

- $d[u]−d[v]>1$    ——      $6-4 > 1$

If $d[u]−d[v]>1$, then there must have been a vertex $t$ that was processed before leading to u being added to the deque where:

- $d[t]≥d[u]−1$     ——       $d[t] ≥ 5$ ,  $d[t] = 5$ or $6$

However that’s impossible, since Dijkstra's algorithm iterates over the vertices in an increasing order.

```cpp
void zero_one_bfs(vvpii &adj, int s){	
    int n = adj.size()-1 ;
    dis.assign(n+1, INT_MAX);
    d[s] = 0;
    deque<int> q;
    q.push_front(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop_front();
        for (pii edge : adj[v]) {
            int u = edge.first;
            int w = edge.second;
            if (d[v] + w < d[u]) {
                d[u] = d[v] + w;
                if (w == 1)
                    q.push_back(u);
                else
                    q.push_front(u);
            }
        }
    }
}
```

## **Dial's Algorithm**

An extension of the 0-1 BFS. If every edge in the graph has a weight $≤k$ , then the distances of vertices in the queue will differ by at most $k$ from the distance of v to the source.

$o(e+wv)$

Note that :

The maximum distance between any two nodes is at most w(v - 1), where w is the maximum edge weight and v - 1 represents the maximum number of edges that can exist between two vertices.

The algorithm uses a bucket-based data structure, where each bucket represents nodes at a specific distance from the source node. The number of buckets is  w(v - 1), representing distances from 0 up to w(v - 1).

```cpp
vector<int> dis;
vector<int> p;
void dial_algorithm(vvpii &adj, int s, int mxW) {
    int n = adj.size() - 1;
    p.assign(n + 1, -1);
    dis.assign(n + 1, INT_MAX);
    dis[s] = 0;
    
    int mxD = (n-1) * mxW; // Max possible distance
    vector<deque<int>> buckets(mxD + 1);
    buckets[0].push_back(s); 
    
    // Current bucket index
    int currentBucket = 0;   
    while (currentBucket <= mxD) {
        // Skip empty buckets
        while (currentBucket <= mxD && buckets[currentBucket].empty())
	        currentBucket++; 
        
        if (currentBucket > mxD) break; // If all buckets are processed
			
        int v = buckets[currentBucket].front();
        buckets[currentBucket].pop_front();
        
        if(dis[v]!=currentBucket) continue ;
        
        for (pii edge : adj[v]) {
            int u = edge.first;
            int w = edge.second;
            if (dis[v] + w < dis[u]) {
                dis[u] =  dis[v] + w;
                buckets[dis[v] + w].push_back(u);
                p[u] = v;
            }
        }
    }
}

```

References:

https://cp-algorithms.com/graph/01_bfs.html

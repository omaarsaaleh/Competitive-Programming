![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/2ce07042-83f8-4a3e-b7d3-d942404ea4c4/7d7dadc7-2231-4b12-927b-d5ddcb7ff900/Untitled.png)

### Graph

Graph is simply a set of vertices and a collection of edges that each connect a pair pf vertices.

### Parallel Edges

Edges that connect the same pair of vertices

### Loop

An edge that connects a vertex to itself.

### Weighted Graph

A graph in which a number (the weight) is assigned to each edge.

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/2ce07042-83f8-4a3e-b7d3-d942404ea4c4/84eaed0f-5182-4c84-9a3d-bf45a02f181b/Untitled.png)

### Simple Graph

An unweighted, undirected graph without parallel edges and loops

### Multigraph

A graph with Parallel Edges.

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/2ce07042-83f8-4a3e-b7d3-d942404ea4c4/6e1f4c7e-0348-485b-ae1b-ef233988c7f7/Untitled.png)

### Complete Graph

A simple undirected graph in which each pair of distinct vertices is connected by a unique edge.

edges = $( nodes * ( nodes - 1 ) ) /  2$   

$\displaystyle\sum_{x=1}^{n-1} x$
 

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/2ce07042-83f8-4a3e-b7d3-d942404ea4c4/0eccd4d3-09b3-4c3a-903b-7b54310d12b6/Untitled.png)

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/2ce07042-83f8-4a3e-b7d3-d942404ea4c4/4f51b56d-c77a-4fe7-b609-02587dac8a53/Untitled.png)

### Bipartite Graphs:

A Graph whose vertices can be partitioned into **two** sets such that there is no two adjacent vertices within the same set (no edges conntect them).

![image.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/2ce07042-83f8-4a3e-b7d3-d942404ea4c4/9b2fc6eb-7ab7-4b58-9208-72d1cf3f826b/image.png)

### (Strongly if directed) Connected Graph

A graph is connected if there is a path from any node to any other node.

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/2ce07042-83f8-4a3e-b7d3-d942404ea4c4/6a88f998-0819-4d80-8ee4-e0a0db9ea169/Untitled.png)

### Disconnected Graph

A graph with at least a node that is not reachable from other nodes.

![image.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/2ce07042-83f8-4a3e-b7d3-d942404ea4c4/1b7d472f-0c0c-445d-a5ca-a72b193a067e/image.png)

### Path

A sequence of vertices connected by edges, Length of a path: Number of edges in the path.

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/2ce07042-83f8-4a3e-b7d3-d942404ea4c4/5c88a2d7-2e1c-4f15-ab6b-2aeb1f0d9214/Untitled.png)

### Simple Path

A path in which each vertex appear no more than one time except for the **cycle**.

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/2ce07042-83f8-4a3e-b7d3-d942404ea4c4/f0395855-14b1-4fc6-9409-d914d61a572c/Untitled.png)

### Cycle

A simple path with at least one edge whose first and last vertices are the same where n0 is the only node appearing more than once and no edges appears more than once in the path sequence. (a loop is not a cycle)

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/2ce07042-83f8-4a3e-b7d3-d942404ea4c4/8b409e31-9383-4b07-a3b2-97aeb6b686a0/Untitled.png)

### Cyclic Graph

A graph containing at least one cycle. 

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/2ce07042-83f8-4a3e-b7d3-d942404ea4c4/6ec1f8c4-b231-46ab-844c-77dc65aa63c0/Untitled.png)

Detecting cycles in a graph is important. For example, a graph that
represents valid course prerequisites should not have any cycles.

### Adjacent vertices

When there is an edge connecting two vertices

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/2ce07042-83f8-4a3e-b7d3-d942404ea4c4/b0305876-56d5-42df-be65-f909134a421c/Untitled.png)

### Adjacent edges

Edges that share a common vertex. (figure 2 not 1)

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/2ce07042-83f8-4a3e-b7d3-d942404ea4c4/72ca57c1-4225-4541-8742-b830576113ab/Untitled.png)

### Incident Edge

When an edge connect some vertex with another one (in and out for directed)

(edge e is said to be incident with vertex u and v)

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/2ce07042-83f8-4a3e-b7d3-d942404ea4c4/9f9cb535-09ad-4f52-9c93-60b12f2506c7/Untitled.png)

### Degree of a vertex

The number of incident edges to it 

### Dense Graph

|E|  e  o( |V$| ^ 2$ )

### Sparse Graph

 |E|  e  o( |V| )

### Adjacency Matrix

(c)

Symmetric for undirected graph

- In some applications it pays off to store only the diagonal and and above data to reduce space into the half.

Space : o( |v$| ^ 2$ )

```cpp
vector<vector<int>> adj(N, vector<int>(N,0));
for (int i = 0; i < edges; ++i) {
	int from, to;
	cin >> from >> to;
	adj[from][to] = 1, adj[to][from] = 1;
}
```

### Adjacency List (array of linked lists)

(b)

Space : o( | V | + | E | ) 

```cpp
vector<vector<int>> adj(N, vector<int>()) ;
for (int i = 0; i < edges; ++i) {
	int from, to;
	cin >> from >> to;
	adj[from].push_back(to);
	adj[to].push_back(from);
}
```

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/2ce07042-83f8-4a3e-b7d3-d942404ea4c4/f52f3522-e5a6-43e3-bae4-ee7549b231ea/Untitled.png)

- For Sparse Graph, List is better in terms of space.
- Sum of lengths of Adjacency List, Directed |E|, Undirected 2|E| as if (u,v) is an edge then v is stored in u and vice versa.

### Tree

A connected acyclic undirected graph. It has n − 1 edges
where n is the number of vertices. Which means that there’s
exactly one path between each pair of nodes.

![image.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/2ce07042-83f8-4a3e-b7d3-d942404ea4c4/703dfc87-ddd0-4aae-b436-31a31f9ea183/image.png)

Reference : https://www.cs.mtsu.edu/~xyang/3080/graph2.html

![Untitled](https://github.com/user-attachments/assets/b3f3243e-ca42-4f8d-a532-6347ed8c47e5)

### Graph

Graph is simply a set of vertices and a collection of edges that each connect a pair pf vertices.

### Parallel Edges

Edges that connect the same pair of vertices

![Untitled 1](https://github.com/user-attachments/assets/4b7c59bb-7079-4e75-ad00-683c22bf6796)

### Loop

An edge that connects a vertex to itself.

![Untitled 2](https://github.com/user-attachments/assets/04641b93-b4d4-4ad1-a85d-1ace8da48b28)

### Weighted Graph

A graph in which a number (the weight) is assigned to each edge.

![Untitled 3](https://github.com/user-attachments/assets/475097f1-683c-4c3e-a91a-e78a49a241a2)

### Simple Graph

An unweighted, undirected graph without parallel edges and loops

![Untitled 4](https://github.com/user-attachments/assets/43690ce8-1270-4fd6-8a82-4c7efa4e1de0)


### Multigraph

A graph with Parallel Edges.

![Untitled 5](https://github.com/user-attachments/assets/0940e181-587a-45a7-bfd6-87983df878b5)


### Complete Graph

A simple undirected graph in which each pair of distinct vertices is connected by a unique edge.

edges = $( nodes * ( nodes - 1 ) ) /  2$   

$\displaystyle\sum_{x=1}^{n-1} x$
 
![Untitled 6](https://github.com/user-attachments/assets/07318d4c-c261-43cf-9d61-5cae375103c5)

![Untitled 7](https://github.com/user-attachments/assets/139d8246-3161-4960-afea-d93edc7b7ffb)


### Bipartite Graphs:

A Graph whose vertices can be partitioned into **two** sets such that there is no two adjacent vertices within the same set (no edges conntect them).

![image](https://github.com/user-attachments/assets/a04450a9-eb82-4f5d-88dd-678c0514ca1c)


### (Strongly if directed) Connected Graph

A graph is connected if there is a path from any node to any other node.

![Untitled 8](https://github.com/user-attachments/assets/f0d967e6-7381-4524-b675-49248fe672d9)


### Disconnected Graph

A graph with at least a node that is not reachable from other nodes.

![image 1](https://github.com/user-attachments/assets/67711f64-f89c-43e5-948e-cd40fea76420)

### Path

A sequence of vertices connected by edges, Length of a path: Number of edges in the path.

![Untitled 9](https://github.com/user-attachments/assets/c58f39a1-02e4-4c16-8579-40736a99656b)


### Simple Path

A path in which each vertex appear no more than one time except for the **cycle**.

![Untitled 10](https://github.com/user-attachments/assets/a5f68b10-e62f-4041-a65d-ac3b0d3ba8c6)


### Cycle

A simple path with at least one edge whose first and last vertices are the same where n0 is the only node appearing more than once and no edges appears more than once in the path sequence. (a loop is not a cycle)

![Untitled 11](https://github.com/user-attachments/assets/2bfe5559-88ca-4c24-aa2f-88894e11d1a2)

### Cyclic Graph

A graph containing at least one cycle. 

![Untitled 12](https://github.com/user-attachments/assets/7a96e1d6-aabe-4319-8434-38e70f7b861b)

Detecting cycles in a graph is important. For example, a graph that
represents valid course prerequisites should not have any cycles.

### Adjacent vertices

When there is an edge connecting two vertices

![Untitled 13](https://github.com/user-attachments/assets/2cfd48a5-af69-428f-9598-7e7926b6bb2d)


### Adjacent edges

Edges that share a common vertex. (figure 2 not 1)

![Untitled 14](https://github.com/user-attachments/assets/6347344a-b102-429d-987b-96137d701a96)

### Incident Edge

When an edge connect some vertex with another one (in and out for directed)

(edge e is said to be incident with vertex u and v)

![Untitled 15](https://github.com/user-attachments/assets/13665db5-571e-4f5d-9651-a2333f2e7f01)


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

![Untitled 16](https://github.com/user-attachments/assets/13d0ab43-e658-4c0f-92a3-272ff68c9ca6)


- For Sparse Graph, List is better in terms of space.
- Sum of lengths of Adjacency List, Directed |E|, Undirected 2|E| as if (u,v) is an edge then v is stored in u and vice versa.

### Tree

A connected acyclic undirected graph. It has n − 1 edges
where n is the number of vertices. Which means that there’s
exactly one path between each pair of nodes.

![image 2](https://github.com/user-attachments/assets/378b94bc-a6d8-4073-b3a2-7606ad52baec)

Reference : ‣Reference : https://www.cs.mtsu.edu/~xyang/3080/graph2.html

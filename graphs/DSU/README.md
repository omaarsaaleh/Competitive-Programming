# DSU Optimization Techniques

## **Finding**

![image](https://github.com/user-attachments/assets/ce4ac786-bdb3-4783-b849-20614ec9bed4)

### **Path Compression**

#### Recursion

```cpp
int Find(int x){
    if ( parent[x] == x) return x;
    return parent[x] = Find( parent[x] );
}
```

#### Two passes Find

```cpp
int Find(int x){
	int root = x
	// get the root
	while (parent[root] != root){ 
		root = parent[root] ;
	}
	// compress the path
	while (parent[x] != root){ 
		int parent = parent[x] ; 
		parent[x] = root ;
		x = parent ; 
	} 
	return root ;

}
```

![image](https://github.com/user-attachments/assets/54f98e77-9bad-48bc-919f-98681a98242b)

### **Path Splitting**

```cpp
int Find(x){
    while (parent[x] != x){
        int parent = parent[x] ;
        parent[x] = parent[ parent[x] ] ;
        x = parent ;
    }
    return x ;
}
```

![image](https://github.com/user-attachments/assets/2e003709-d7f1-4a7b-9005-fe1aa5a5b64b)

### **Path halving**

```cpp
int Find(x){
    while (parent[x] != x){
        parent[x] = parent[ parent[x] ] ;
        x = parent[x] ;
    }
    return x ;
}
```

![works similarly but replaces only every other parent pointer (skips one node)](https://github.com/user-attachments/assets/1c2cf257-75ad-4dda-9090-ca9bde14bea2)

works similarly but replaces only every other parent pointer (skips one node)

## Union

The choice of which node becomes the parent has consequences for the complexity of future operations on the tree.  If it is done carelessly, it can lead to treas containing chains of length O(n).

It’s always better to attach the smaller tree (the tree with the lower rank) under the root of the larger tree (the one with the bigger rank). By doing this, the overall height of the resulting tree is minimized.
(Parent of the small = Large)

![image](https://github.com/user-attachments/assets/665f5240-d296-4150-8b12-6404a2b45be5)

### Union by Size

```cpp
void Union(int u, int v){
	int par1 = Find(u), par2 = Find(v);	
	if(par1 == par2) return;

// ensure that par1 is the representative of the tree with the smaller size
	if(sz[par1] > sz[par2]) 
		swap(par1, par2);

	sz[par2] += sz[par1];
	sz[par1] = 0;
	parent[par1] = par2;
}
```

### Union by Rank

The rank is not the exact height of the tree but is an upper bound of the height.
because the depth will get smaller when calling find() (applying path compression).

```cpp
void Union(int u, int v) {
    int par1 = Find(u), par2 = Find(v);	
    if(par1 == par2) return;
        
    if (rank[par1] > rank[par2])
        swap(par1, par2);
    
     parent[par1] = par2; 
     // height increased by one
     if (rank[par1] == rank[par2]) 
         rank[par2]++;
}
```

**If the ranks are different** 
Just ****attach the tree with the lower rank under the tree with the higher rank.

**If the ranks are the same** 
You can attach one tree under the other and increment the rank of the new root by 1 because the height of the tree increases by 1.

### Union by Index

We assign each set a random value called the index, and we attach the set with the smaller index to the one with the larger one (we keep taking the higher index). It is likely that a bigger set will have a bigger index than the smaller set, therefore this operation is closely related to union by size. 
Same time complexity as union by size, but in practice it is slightly slower .

```cpp
void make_set(int v) {
    parent[v] = v;
    index[v] = rand();
}

void Union(int u, int v) {
    int par1 = Find(u), par2 = Find(v);	
    if(par1 == par2) return;
        
    if (index[par1] > index[par2])
        swap(par1, par2);

    parent[par1] = par2;
}
```

### Union by coin-flip

Worse

```cpp
void Union(int u, int v) {
    int par1 = Find(u), par2 = Find(v);
    if(par1 == par2) return;
    
    if (rand() % 2)
	    swap(par1, par2);
        parent[par1] = par2;
    
}
```

References :  
https://cp-algorithms.com/data_structures/disjoint_set_union.html  
https://en.wikipedia.org/wiki/Disjoint-set_data_structure

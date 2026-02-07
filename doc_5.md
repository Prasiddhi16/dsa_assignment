Program 5: Undirected Graph Traversal using Adjacency Matrix
(A) Data Structures Defined
- A global integer 2d array mat[max][max] is defined.
- max is the maximum size of the matrix (10).
- visit[max] is an integer array that tracks visited vertices.
- The adjacency matrix is symmetric since the graph is undirected.

(B) Functions
1: add(int v, int w)
- adds an edge between vertex v and w.
- updates both mat[v][w] and mat[w][v] to 1.
2: bfs(int start, int vertices)
- implements breadth first search traversal.
- uses a queue array queue[max] with front and rear indices.
- initializes all vertices as unvisited.
- pushes the starting vertex into the queue.
- iteratively dequeues and prints nodes, enqueues unvisited neighbors.
3: dfsutil(int node, int vertices)
- recursive helper for dfs traversal.
- marks the current node as visited.
- prints the node.
- recursively visits all unvisited neighbors.
4: dfs(int start, int vertices)
- initializes all vertices as unvisited.
- calls dfsutil() starting from the given vertex.
- prints the traversal order.

(C) The main() function
- defines vertices = 5.
- initializes the adjacency matrix with all zeros.
- adds edges:
- 0–1, 0–2, 1–3, 2–4.
- calls bfs(0, vertices) and dfs(0, vertices) to demonstrate traversal.
- prints the traversal results.

(D) Output
breadth first search:
0 1 2 3 4
dfs traversal:
0 1 3 2 4





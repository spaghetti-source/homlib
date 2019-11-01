# homlib --- Homomorphism Counting Algorithm

## Description

A C++ implementation of homomorphism counting algorithm.

## Algorithm

It is a dynamic programming on tree decomposition.

- For tree decomposition, it uses the greedy heuristics.
- For homomorphism counting, I implemented [1]. 

[1] Josep Diaz, Maria Serna, Dimitrios M. Thilikos (2002): "Counting H-colorings of partial k-trees", Theoretical Computer Science, 281 (2002), 291 – 309.

## Usage

````
from homlib import Graph, hom
T = Graph(3)
T.addEdge(0,1)
T.addEdge(1,2)

G = Graph(3)
G.addEdge(0,1)
G.addEdge(1,2)
G.addEdge(2,0)

print(hom(T, G))
````

## Author

Takanori Maehara (maehara@prefield.com)

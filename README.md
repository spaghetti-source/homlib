# homlib --- An implementation of a Homomorphism Counting Algorithm

## Description

This library computes the number of graph homomophisms.


This implements Diaz--Serna--Thilikos's dynamic programming algorithm on a nice tree decomposition, where the greedy heuristics is used to find a tree decomposition.

Josep Diaz, Maria Serna, Dimitrios M. Thilikos (2002): "Counting H-colorings of partial k-trees", Theoretical Computer Science, 281 (2002), 291 – 309.

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

## Install

### C++

````
https://github.com/spaghetti-source/homlib/
cd homlib
make
````

### Python

````
https://github.com/spaghetti-source/homlib/
pip3 install ./homlib
````

## Uninstall

### C++

````
rm homlib
````

### Python

````
pip3 uninstall homlib
rm homlib
````

## Author

Takanori Maehara (maehara@prefield.com)

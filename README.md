# homlib --- Homomorphism Counting Algorithm

## Description

A C++ implementation of graph homomorphism counting algorithm and a Python interface.


This implements Diaz--Serna--Thilikos's dynamic programming algorithm on a nice tree decomposition, where the greedy heuristics to find a tree decomposition.

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

### Compile

require:
- boost::python
- g++ supporting -c++17 option

````
make
````

### Install

copy ./build/homlib.so to a suitable directory.


## Author

Takanori Maehara (maehara@prefield.com)

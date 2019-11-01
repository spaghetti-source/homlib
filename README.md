# homlib --- Homomorphism Counting Algorithm

## Usage

````
import homlib

F = homlib.Graph(3)
F.addEdge(0, 1)
F.addEdge(1, 2)
F.addEdge(2, 0)

G = homlib.Graph(4)
G.addEdge(0, 1)
G.addEdge(1, 2)
G.addEdge(2, 0)
G.addEdge(1, 3)
G.addEdge(3, 2)

print(homlib.hom(F, G))
````

# Author

Takanori Maehara (maehara@prefield.com)

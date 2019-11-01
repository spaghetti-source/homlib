// g++ -O3 -fmax-errors=1 -fsanitize=undefined -fsanitize=address -sanitize=leak 
//
// https://core.ac.uk/download/pdf/82380292.pdf
//
#include <bits/stdc++.h>
#include "hom.hh"

using namespace std;

int mainx() {
  int t = 4;
  Graph T(t);
  T.addEdge(0, 1);
  T.addEdge(1, 2);
  T.addEdge(1, 3);

  int n = 4;
  Graph G(n);
  G.addEdge(0, 1);
  G.addEdge(1, 2);
  G.addEdge(2, 3);
  G.addEdge(3, 0);
  G.addEdge(0, 2);
  cout << hom(T, G) << endl;
  return 0;
}

int main() {
  int t = 10;
  Graph T(t);
  for (int i = 1; i < t; ++i) 
    T.addEdge(rand() % i, i);

  int n = 500;
  Graph G(n);
  for (int i = 0; i < n; ++i) 
    for (int j = i+1; j < n; ++j) 
      if (rand() % 3 == 0) 
        G.addEdge(i, j);

  cout << hom(T, G) << endl;
  return 0;
}

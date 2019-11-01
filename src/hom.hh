#pragma once

#include <bits/stdc++.h>
#include "graph.hh"
#include "treedec.hh"

template <class Value>
struct HomomorphismCounting {
  using MapType = std::vector<int>;
  struct VectorHash {
    size_t operator()(const std::vector<int> &x) const {
      constexpr size_t p = 1e9+7;
      size_t hash = 0;
      for(int i = 0; i < x.size(); ++i) {
        hash += p * hash + x[i];
      }
      return hash;
    }
  };
  using MapDict = std::unordered_map<MapType, Value, VectorHash>;

  template <class It>
  static bool next_radix(It begin, It end, int base) {
    for (It cur = begin; cur != end; ++cur) {
      if ((*cur += 1) >= base) *cur = 0;
      else return true;
    }
    return false;
  }
  static std::vector<std::vector<int>> allMaps(int t, int n) {
    std::vector<int> v(t);
    if (t == 0) return {v};
    std::vector<std::vector<int>> maps;
    do {
      maps.push_back(v);
    } while (next_radix(v.begin(), v.end(), n));
    return maps;
  }

  Graph F, G;
  NiceTreeDecomposition NTD;

  HomomorphismCounting(Graph F_, Graph G_) : F(F_), G(G_) {
    for (int a = 0; a < G.n; ++a) {
      sort(G.adj[a].begin(), G.adj[a].end());
    }
    for (int u = 0; u < F.n; ++u) {
      sort(F.adj[u].begin(), F.adj[u].end());
    }
    NTD = niceTreeDecomposition(F);
  }
  Value run() {
    auto [I, X] = run(NTD.root);
    return I[MapType()];
  }
  template <class It, class T>
  static int index(It begin, It end, T x) {
    return distance(begin, lower_bound(begin, end, x));
  }
  std::pair<MapDict, std::vector<int>> run(int x) {
    MapDict I;
    if (NTD.type(x) == NiceTreeDecomposition::INTRODUCE && NTD.child(x) == -1) {
      std::vector<int> X = {NTD.vertex(x)};
      for (auto phi: allMaps(1, G.n)) {
        I[phi] = 1;
      }
      return make_pair(I, X);
    } 
    if (NTD.type(x) == NiceTreeDecomposition::INTRODUCE) {
      auto [J, X] = run(NTD.child(x));
      int k = index(X.begin(), X.end(), NTD.vertex(x));

      for (auto phi: allMaps(X.size(), G.n)) {
        std::vector<int> nbh;
        for (int u: F.adj[NTD.vertex(x)]) {
          int i = index(X.begin(), X.end(), u);
          if (i != X.size()) {
            nbh.push_back(phi[i]);
          }
        }
        auto psi = phi;
        psi.insert(psi.begin()+k, 0);
        for (int a = 0; a < G.n; ++a) {
          psi[k] = a;
          bool condition = true;
          for (int b: nbh) {
            if (!binary_search(G.adj[a].begin(), G.adj[a].end(), b)) {
              condition = false;
              break;
            }
          }
          if (condition) {
            I[psi] = J[phi];
          }
        }
      }
      X.insert(X.begin()+k, NTD.vertex(x));
      return make_pair(I, X);
    } 
    if (NTD.type(x) == NiceTreeDecomposition::FORGET) {
      auto [J, X] = run(NTD.child(x));
      int k = index(X.begin(), X.end(), NTD.vertex(x));
      X.erase(X.begin()+k);
      for (auto phi: allMaps(X.size(), G.n)) {
        auto psi = phi;
        psi.insert(psi.begin()+k, 0);
        for (int a = 0; a < G.n; ++a) {
          psi[k] = a;
          I[phi] += J[psi];
        }
      }
      return make_pair(I, X);
    } 
    if (NTD.type(x) == NiceTreeDecomposition::JOIN) {
      auto [J, X] = run(NTD.left(x));
      auto [K, Y] = run(NTD.right(x));
      assert(X == Y);
      for (auto phi: allMaps(X.size(), G.n)) {
        I[phi] = J[phi] * K[phi];
      }
      return make_pair(I, X);
    }
    assert(false);
  }
};

template <class Value>
Value hom(Graph F, Graph G) {
  Value value = 0;
  for (auto Gi: connectedComponents(G)) {
    value += HomomorphismCounting<Value>(F, Gi).run();
  }
  return value;
}


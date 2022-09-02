#include <vector>

struct Edge {
  int v;
  int w;
  Edge(int v = -1, int w = -1) : v{v}, w{w} {}
};

class DenseGRAPH {
private:
  int Vcnt;
  int Ecnt;
  bool digraph;
  std::vector<std::vector<bool>> adj;

public:
  DenseGRAPH(int, bool);
  int V() const { return Vcnt; }
  int E() const { return Ecnt; }
  bool directed() const { return digraph; }
  void insert(Edge);
  void remove(Edge);
  bool edge(int v, int w) const { return adj[v][w]; }
  class adjIterator {
  private:
    const DenseGRAPH &G;
    int i;
    int v;

  public:
    adjIterator(const DenseGRAPH &, int);
    int beg() {
      i = -1;
      return nxt();
    }
    int nxt();
    bool end() { return i >= G.V(); }
  };

  friend class adjIterator;
};

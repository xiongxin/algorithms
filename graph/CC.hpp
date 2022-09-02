template <typename Graph> class CC {
private:
  // implementation-dependent code
  const Graph &G;

public:
  CC(const Graph &);
  int count();
  bool connect(int, int);
};

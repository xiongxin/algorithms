#include "../../DenseGRAPH.hpp"
#include "../../IO.hpp"

int main(int argc, char const *argv[]) {
  DenseGRAPH dg{100, false};
  IO<DenseGRAPH>::scanEZ(dg);
  IO<DenseGRAPH>::show(dg);

  return 0;
}

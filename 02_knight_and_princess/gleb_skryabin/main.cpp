#include <array>
#include <vector>
#include "graph.hpp"

int main(void) {
  const std::array<Graph::Edge, 18> edges = {{{0, {0, 1}},
                                              {1, {0, 2}},
                                              {2, {0, 3}},
                                              {3, {1, 4}},
                                              {4, {1, 5}},
                                              {5, {1, 6}},
                                              {6, {2, 7}},
                                              {7, {2, 8}},
                                              {8, {3, 9}},
                                              {9, {4, 10}},
                                              {10, {5, 10}},
                                              {11, {6, 10}},
                                              {12, {7, 11}},
                                              {13, {8, 11}},
                                              {14, {9, 12}},
                                              {15, {10, 13}},
                                              {16, {11, 13}},
                                              {17, {12, 13}}}};

  Graph g(edges);
  g.printJSON("graph.json");
  return 0;
}

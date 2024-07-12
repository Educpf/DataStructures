
#include "Linked_List.h"
#include <iostream>
#include <utility>

void print(LinkedList<std::pair<int, int>> &list) {
  for (std::pair<int, int> i : list) {
    std::cout << i.first << ".." << i.second << " | ";
  }
  std::cout << '\n';
}

int main() {

  LinkedList<std::pair<int, int>> list{{1, 2}, {2, 4}};
  print(list);
  LinkedList<std::pair<int, int>>::Iterator cit = list.begin();
  std::cout << cit->first << '\n';
  LinkedList<std::pair<int, int>>::Iterator it = list.begin();
  *it = {1, 7};
  print(list);
  std::cout << it->second;

  return 0;
}

#include <iostream>

#include "vecap.h"

int main() {
  container::Vecap<std::string, int> vecap = {
      {"Key0", 0},
      {"Key1", 1},
      {"Key2", 2},
      {"Key3", 3},
      {"Key4", 4},
      {"Key5", 5},
      {"Key6", 6}};

  vecap[2] = 22;
  vecap[5] = 55;

  std::cout << vecap.size() << std::endl;

  for (auto value : vecap) {
    std::cout << value << ' ';
  }

  std::cout << std::endl;

  std::cout << *vecap.find("Key0") << ' ';
  std::cout << *vecap.find("Key5") << ' ';
  std::cout << *vecap.find("Key6") << std::endl;

  vecap.erase(vecap.find("Key2"));
  std::cout << vecap.size() << std::endl;

  std::cout << vecap[4] << std::endl;

  for (auto value : vecap) {
    std::cout << value << ' ';
  }

  std::cout << std::endl;

  return 0;
}

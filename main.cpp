#include <iostream>
#include <vector>

int bricksAndWater(const std::vector<int>& bricksArray) {
  int retValue = 0;
  int start = 0;
  int end = bricksArray.size() - 1;
  std::vector<int> water;

  for (int index = 0; index < (int)bricksArray.size(); index++) {
    if (bricksArray[index] >= bricksArray[start]) {
      for (int index2 = 0; index2 < (int)water.size(); index2++)
        retValue += bricksArray[start] - water[index2];

      water.clear();

      start = index;
    } else
      water.push_back(bricksArray[index]);
  }

  water.clear();

  for (int index = bricksArray.size() - 1; index >= start; index--) {
    if (bricksArray[index] >= bricksArray[end]) {
      for (int index2 = water.size() - 1; index2 >= 0; index2--)
        retValue += bricksArray[end] - water[index2];

      water.clear();

      end = index;
    } else
      water.push_back(bricksArray[index]);
  }

  return retValue;
}

int main() {
  std::vector<int> bricksArray = {2, 0, 2};

  std::cout << ((bricksAndWater(bricksArray) == 2) ? "ok" : "fail")
            << std::endl;

  bricksArray = {1, 0, 2, 1};

  std::cout << ((bricksAndWater(bricksArray) == 1) ? "ok" : "fail")
            << std::endl;

  bricksArray = {2, 0, 3, 0, 4};

  std::cout << ((bricksAndWater(bricksArray) == 5) ? "ok" : "fail")
            << std::endl;

  bricksArray = {4, 0, 2, 0, 1};

  std::cout << ((bricksAndWater(bricksArray) == 3) ? "ok" : "fail")
            << std::endl;

  bricksArray = {4, 0, 5, 0, 1};

  std::cout << ((bricksAndWater(bricksArray) == 5) ? "ok" : "fail")
            << std::endl;

  bricksArray = {4, 0, 0, 2, 1};

  std::cout << ((bricksAndWater(bricksArray) == 4) ? "ok" : "fail")
            << std::endl;

  return 0;
}

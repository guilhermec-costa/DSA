#include <cstdlib>
#include <iostream>
#include <string>

void str_score(std::string s) {
  int sum = 0;
  for (int i = 0; i < s.length() - 1; i++) {
    sum += std::abs(static_cast<int>(s[i]) - static_cast<int>(s[i + 1]));
  }
  std::cout << "Sum: " << sum << "\n";
}
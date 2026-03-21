#include <iostream>
#include <string>

void remove_spaces(std::string s) {
  int w = 0;

  for (int r = 0; r < s.size(); r++) {
    if (!std::isspace(s[r])) {
      s[w++] = s[r];
    }
  }

  s.resize(w);

  std::cout << "String without spaces: " << s << "\n";
}
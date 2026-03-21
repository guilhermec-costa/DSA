#include <string>

using std::string;

std::string merge_alternately(string word1, string word2) {
  std::string merged;
  merged.reserve(word1.size() + word2.size());

  int i = 0;
  for (; i < std::min(word1.size(), word2.size()); i++) {
    merged += word1[i];
    merged += word2[i];
  }

  merged += word1.substr(i);
  merged += word2.substr(i);
  return merged;
}
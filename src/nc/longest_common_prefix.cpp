#include <string>
#include <vector>

using std::string;
using std::vector;

string longest_common_prefix(std::vector<string>& strs) {
  if(strs.empty()) return "";
  if(strs.size() == 1) return strs[0];

  int smaller_len = strs[0].size();
  for(int i=1;i<strs.size();i++) {
    if(strs[i].size() < smaller_len) {
      smaller_len = strs[i].size();
    }
  }

  std::string prefix = "";
  for(int i=0; i<smaller_len;i++) {
    char last_char = strs[0][i];
    for(const auto& str : strs) {
      if(str[i] != last_char) {
        return prefix;
      }
    }
    prefix += last_char;
  }
  return prefix;
}
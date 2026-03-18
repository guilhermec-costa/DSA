#include <string>
#include <unordered_map>

bool valid_anagram(std::string s, std::string t) {
  if(s.size() != t.size()) return false;

  std::unordered_map<char, int> sM, tM;
  for(int i=0; i<s.size();i++) {
    sM[s[i]]++;
    tM[t[i]]++;
  }

  for(const auto& [k, v] : sM) {
    if(tM[k] != v) return false; 
  }
  return true;
}
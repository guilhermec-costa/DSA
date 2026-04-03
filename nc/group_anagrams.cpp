#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::unordered_map;
using std::vector;

/*
Input: strs = ["act","pots","tops","cat","stop","hat"]
Output:       [["hat"],["act", "cat"],["stop", "pots", "tops"]]
*/
static bool is_anagram(string s1, string s2) {
  if (s1.size() != s2.size())
    return false;

  unordered_map<char, int> s1_m = {}, s2_m = {};
  for (int i = 0; i < std::min(s1.size(), s2.size()); i++) {
    s1_m[s1[i]]++;
    s2_m[s2[i]]++;
  }
  for (const auto &[k, v] : s1_m)
    if (v != s2_m[k])
      return false;

  return true;
};

static bool is_anagram2(string s1, string s2) {
  // std::sort normalizes the string
  std::sort(s1.begin(), s1.end());
  std::sort(s2.begin(), s2.end());
  return s1 == s2;
}

vector<vector<string>> group_anagrams2(vector<string> &strs) {
  unordered_map<string, vector<string>> groups = {};

  for (string &str : strs) {
    string key = str;
    std::sort(key.begin(), key.end());
    groups[key].push_back(str);
  }

  vector<vector<string>> output;
  for (const auto &[_, gp] : groups)
    output.push_back(gp);
  return output;
}

vector<vector<string>> group_anagrams(vector<string> &strs) {
  unordered_map<string, bool> compared = {};
  vector<vector<string>> output;

  for (int i = 0; i < strs.size(); i++) {
    if (compared[strs[i]])
      continue;

    vector<string> state{strs[i]};
    for (int r = i + 1; r < strs.size(); r++) {
      if (is_anagram(strs[i], strs[r])) {
        state.push_back(strs[r]);
        compared[strs[r]] = true;
      }
    }
    output.push_back(state);
  }
  return output;
}
#include <string>
#include <vector>

static bool check_palindrome(const std::string_view& str_view) {
  int left = 0;
  int right = str_view.size() - 1;

  while(left < right) {
    while(left < right && !std::isalnum(str_view[left])) left++;
    while(left < right && !std::isalnum(str_view[right])) right--;

    if(std::tolower(str_view[left]) != std::tolower(str_view[right])) {
      return false;
    }

    left++;
    right--;
  }

  return true;
}

bool valid_palindrome_v2(std::string s) {
  std::vector<std::string> variations;
  int idx_var = 0;

  std::string var_str = "";
  for(int i=0; i<s.size();i++) {
    if(i == 0) variations.push_back(s.substr(1));
    else {
      std::string tmp = "";
      tmp += s.substr(0, i) + s.substr(i + 1);
      variations.push_back(tmp);
    }
  }

  for(const auto& str : variations) {
    if(check_palindrome(str)) {
      return true;
    }
  }

  return false;
}
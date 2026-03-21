#include <string>

bool is_valid_palindrome(std::string s) {
  int j = 0;
  for(int i=0; i<s.size();i++) {
    if(std::isalnum(s[i])) {
      if(s[i] >= 'A' && s[i] <= 'Z') {
        s[i] = s[i] + ('a' - 'A');
      }
      s[j++] = s[i];
    }
  }

  s.resize(j);
  std::string prev = s;
  char* p = &(s[0]);
  char* P = &(s[s.size() - 1]);

  while(p < P) {
    char tmp = *p;
    *p = *P;
    *P = tmp;
    p++; P--;
  }

  return prev == s;
}

bool is_valid_palindrome2(std::string s) {
  int left = 0;
  int right = s.size() - 1;

  while(left < right) {
    while(left < right && !std::isalnum(s[left])) left++;
    while(left > right && !std::isalnum(s[right])) right--;

    if(std::tolower(s[left]) != std::tolower(s[right])) {
      return false;
    }

    left++;
    right--;
  }

  return true;
}
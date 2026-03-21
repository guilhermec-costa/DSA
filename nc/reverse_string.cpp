#include <vector>

void reverse_string(std::vector<char>& s) {
  char* p = &(s[0]);
  char* P = &(s[s.size() - 1]);

  while(p<P) {
    char tmp = *p;
    *p = *P;
    *P = tmp;
    p++; P--;
  }
}
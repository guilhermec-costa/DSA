#include "./fundamentals/arrays_adt2.hpp"
#include "./include/stack_adt.h"
#include "./include/doubly_linked_list.h"
#include <cstdlib>
#include <cstring>
#include <string_view>
#include <vector>

using std::vector;
using std::string;

struct ListNode;
extern void revisions();

extern void recursion();
extern void arrays();
extern void arrays_adt();
extern void linked_lists();
extern void linked_list_revision();
extern void strings();
extern void queues();
extern void stacks();
extern void heaps();
extern void binary_trees();
extern void array_concatenation(std::vector<int> &nums);
extern void str_score(std::string s);
extern void reverse_string(std::vector<char> &s);
extern int binary_search(std::vector<int> &nums, int target);
extern int remove_element(std::vector<int> &nums, int val);
extern ListNode *mergeTwoLL(ListNode *list1, ListNode *list2);
extern int majority_element(std::vector<int> &nums);
extern bool is_valid_palindrome(std::string s);
extern void remove_spaces(std::string s);
extern bool valid_palindrome_v2(std::string s);
extern std::string merge_alternately(std::string word1, std::string word2);
extern void hash_main();
extern int remove_duplicates(std::vector<int> &nums);
extern int sqrt_of_x(int x);
extern void infix_to_postfix();
extern std::vector<int> prefix_sum(std::vector<int> &nums);
extern std::vector<int> prefix_sum2(std::vector<int> &nums);
extern void sliding_window();
extern vector<vector<string>> group_anagrams(vector<string> &strs);

bool is_balanced(std::string &expr) {
  StackLL exprSt;
  for (char c : expr) {
    if (c == '(')
      exprSt.push((int)c);

    if (c == ')') {
      const char res = exprSt.pop();
      // only valid when there is more ")" than "("
      if (res == -1) {
        return false;
      }
    }
  }

  return exprSt.is_empty();
}

int main() {
  // revisions();
  // recursion();
  // arrays();
  // arrays_adt();
  // arrays_adt2();
  // strings();
  // linked_lists();
  // linked_list_revision();
  // stacks();
  // queues();
  // heaps();
  // binary_trees();

  // std::vector<int> nums = { 1, 2, 3};
  // array_concatenation(nums);

  // str_score("neetcode");
  // std::vector<char> str = {'h', 'e', 'l', 'l', 'o'};
  // std::cout << "Before reversing: " << "\n";
  // std::for_each(str.begin(), str.end(), [](char c) { std::cout << c; });
  // reverse_string(str);
  // std::cout << "\n";
  // std::cout << "After reversing: " << "\n";
  // std::for_each(str.begin(), str.end(), [](char c) { std::cout << c; });

  // std::vector<int> nums = { 1, 2, 3, 3};
  // std::cout << "Majority element: \n" << majority_element(nums);

  // std::string word = "Was it a car or a cat I saw?";
  // std::string word2 = "tab a cat";
  // std::cout << "Is Valid palindrome: " << is_valid_palindrome(word) << "\n";

  // remove_spaces("hello world again");

  // std::cout << "Is valid palindrome: " << valid_palindrome_v2("hello") <<
  // "\n";

  // std::string merged = merge_alternately("hello", "world");
  // std::cout << "Merged: " << merged << "\n";
  // hash_main();

  // std::vector<int> testcase1{1, 1, 2, 3, 4};
  // std::vector<int> testcase2{-50,-50,-49,-48,-48,-47};
  // std::vector<int> testcase3{ 10,10,10,11,11,12};
  // const int unique_count = remove_duplicates(testcase3);
  // for (const int &i : testcase3) {
  //   std::cout << "Item: " << i << "\n";
  // }
  // std::cout << "Unique count: " << unique_count << "\n";

  // int num = 2147395600;
  // printf("Square root of %d is %d\n", num, sqrt_of_x(num));

  MyStackADT st(5);
  st.push(1);
  st.push(2);
  st.push(10);
  printf("Size: %d\n", st.size());
  printf("Top: %d\n", st.stacktop());
  int last = st.pop();
  printf("Popped: %d\n", last);
  printf("Top: %d\n", st.stacktop());
  st.push(15);
  st.push(30);
  st.display();
  printf("Peek of 3: %d\n", st.peek(3));

  // ---------------
  StackLL stNode;
  stNode.push(5);
  stNode.push(10);
  stNode.push(15);
  stNode.display();

  printf("Peek at 1: %d\n", stNode.peek(4));
  printf("Stacktop of node: %d\n", stNode.stacktop());
  int valPopped = stNode.pop();
  printf("display after pop: ");
  stNode.display();
  printf("Popped element: %d\n", valPopped);
  stNode.pop();
  stNode.display();
  stNode.pop();
  stNode.display();
  stNode.pop();
  stNode.display();

  // if all parenthesis have a matching parenthesis, than the expression is
  // correct
  // std::string expr = "((a+b)*(c-d))";
  // printf("\n--------");
  // printf("\nIs %s balanced? %b\n", expr.c_str(), is_balanced(expr));

  // printf("---------------\n");
  // infix_to_postfix();

  // std::vector<int> v{1, 2, 3, 4, 5};
  // prefix_sum(v);
  // printf("\n");
  // prefix_sum2(v);
  // printf("\n");
  // sliding_window();
  printf("\n");
  vector<string> v {"act","pots","tops","cat","stop","hat"};
  group_anagrams(v);
  printf("Test boolean: %b", !!"");
  
  printf("\n");
  std::string a = "muito grande...";
  printf("A content: %s\n", a.c_str());
  printf("A address: %p\n", &a[0]);
  std::string b = std::move(a);
  printf("A content: %s", a.c_str());
  printf("A address: %p\n", &a[0]);
  printf("B content: %s\n", a.c_str());
  printf("\n");
  doubly_linked_list();
}

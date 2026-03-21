#include "./arrays_adt2.hpp"
#include <algorithm>
#include <vector>

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
extern int binary_search(std::vector<int>& nums, int target);
extern int remove_element(std::vector<int>& nums, int val);
extern ListNode* mergeTwoLL(ListNode* list1, ListNode* list2);
extern int majority_element(std::vector<int>& nums);
extern bool is_valid_palindrome(std::string s);
extern void remove_spaces(std::string s);

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

  std::string word = "Was it a car or a cat I saw?";
  std::string word2 = "tab a cat";
  std::cout << "Is Valid palindrome: " << is_valid_palindrome(word) << "\n";

  remove_spaces("hello world again");
}

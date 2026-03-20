#pragma once

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0) {};
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeTwoLL(ListNode *list1, ListNode *list2);
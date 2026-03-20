#include "../include/linked_list.h"
#include <iostream>

typedef struct Node Node;

struct Node {
  int data;
  Node *next = nullptr;
};

void display_linked_list(Node *node) {
  if (!node)
    return;
  std::cout << "Value: " << node->data << " | Next: " << node->next << "\n";
  display_linked_list(node->next);
}

void display_linked_list_loop(Node *node) {
  // Node *p = node;
  while (node) {
    std::cout << "Value: " << node->data << " | Next: " << node->next << "\n";
    node = node->next;
  }
}

int sum_of_elements(Node *node) {
  if (!node)
    return 0;
  return sum_of_elements(node->next) + node->data;
}

int max_linked_list(Node *node) {
  int max = node->data;
  while (node) {
    if (node->data > max)
      max = node->data;
    node = node->next;
  }

  return max;
}

static Node *search(Node *node, int key) {
  std::cout << "Searching for element " << key << "\n";

  if (!node)
    return nullptr;

  if (node->data == key)
    return node;

  return search(node->next, key);
}

// insert before first, is O(1)
// insert at n pos is O(n)
static void insert(Node *&head, int index, int el) {
  if (index < 0)
    return;

  Node *t = new Node{el};
  if (index == 0) {
    t->next = head;
    head = t;
    return;
  }

  Node *head_cp = head;
  for (int i = 0; i < index - 1; i++) {
    head_cp = head_cp->next;
    std::cout << "Index on insert: " << i << "\n";
  }

  if (!head_cp)
    return;

  t->next = head_cp->next;
  head_cp->next = t;
}

static void _delete(Node *&head, int index) {
  if (index < 0 || !head)
    return;

  if (index == 0) {
    Node *tmp = head;
    head = head->next;
    delete tmp;
    return;
  }

  Node *p = head;
  Node *q = nullptr;

  for (int i = 0; i < index && p; i++) {
    q = p;
    p = p->next;
  }

  if (!p)
    return;

  q->next = p->next;
  delete p;
}

static void _reverse(Node *&head) {
  Node *prev = nullptr;
  Node *curr = head;
  Node *next = nullptr;

  while (curr) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  head = prev;
};

static void Reverse(Node *&head) {
  Node *prev = nullptr;
  Node *curr = head;
  Node *next = nullptr;

  while (curr) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  head = prev;
}

Node *make_LL_from_arr(int *arr, int len) {
  if (len <= 0)
    return nullptr;

  Node *head = new Node{arr[0]};
  Node *curr = head;

  for (int i = 1; i < len; i++) {
    Node *n = new Node{arr[i]};
    curr->next = n;
    curr = n;
  }

  return head;
}

ListNode *make_LL_from_arr_lst_node(int *arr, int len) {
  if (len <= 0)
    return nullptr;

  ListNode *head = new ListNode(0, nullptr);
  ListNode *curr = head;

  for (int i = 1; i < len; i++) {
    ListNode *n = new ListNode(arr[i]);
    curr->next = n;
    curr = n;
  }

  return head;
}

void linked_list_revision() {
  std::cout << "--------\n";
  Node *head = new Node;
  std::cout << "Head before: " << head << "\n";
  head->data = 1;

  Node *second = new Node;
  second->data = 2;
  second->next = nullptr;

  head->next = second;

  Node *third = new Node;
  third->data = 3;
  second->next = third;

  display_linked_list(head);
  std::cout << "--------\n";
  display_linked_list_loop(head);

  std::cout << "Head after: " << head << "\n";

  std::cout << "Sum: " << sum_of_elements(head) << "\n";

  std::cout << "Max: " << max_linked_list(head) << "\n";

  Node *target = search(head, 3);

  std::cout << "Target Address: " << target
            << " | Target value: " << target->data << "\n";

  insert(head, 0, 125);
  insert(head, 2, 150);

  display_linked_list(head);

  int x[] = {5, 10, 15, 20, 25};
  Node *ll = make_LL_from_arr(x, 5);
  display_linked_list(ll);

  std::cout << "--------\n";
  _delete(ll, 2);
  display_linked_list(ll);
  std::cout << "--------\n";
  _delete(ll, 0);
  display_linked_list(ll);

  int arr_rev[] = {1, 2, 3, 4, 5};
  Node *ll_to_rev = make_LL_from_arr(arr_rev, 5);
  std::cout << "--------\n";
  std::cout << "Before reverse \n";
  display_linked_list(ll_to_rev);
  Reverse(ll_to_rev);

  std::cout << "After reverse \n";
  display_linked_list(ll_to_rev);

  std::cout << "Mergint linked list\n";

  int to_merge[] = {1,2,3,4};
  ListNode* list1 = make_LL_from_arr_lst_node(to_merge, 4);
  ListNode* list2 = make_LL_from_arr_lst_node(to_merge, 4);
  ListNode* merged = mergeTwoLL(list1, list2);

  ListNode* curr = merged;
  while(curr) {
    std::cout << "Display: " << curr->val << "\n";
    curr = curr->next;
  }

  std::cout << "------\n";
  delete head;
  delete second;
  delete third;
}
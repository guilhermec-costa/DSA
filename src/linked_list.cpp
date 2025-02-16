#include <iostream>
#include <limits>

struct Node
{
  int data;
  // pointer to a memory location, where another Node is stored
  // self-referential structure
  struct Node *next;
}; // 4 bytes total

int count_linked_list_nodes(Node *n)
{
  if (!n->next)
    return 1;

  return count_linked_list_nodes(n->next) + 1;
};

void display_nodes(Node *n)
{
  std::cout << n->data << std::endl;
  if (!n->next)
    return;

  display_nodes(n->next);
}

void recursive_display(struct Node *cur_node)
{
  if (cur_node != NULL)
  {
    std::cout << cur_node->data << std::endl;
    recursive_display(cur_node->next);
  }
}

void backwards_recursive_display(struct Node *cur_node)
{
  struct Node *p_cp = cur_node;
  if (p_cp != NULL)
  {
    backwards_recursive_display(p_cp->next);
    std::cout << p_cp->data << std::endl;
  }
}

struct Node *create_linked_list(int a[], int n)
{
  int i = 0;
  struct Node *t, *last;
  struct Node *first = new Node;
  first->data = a[0];
  first->next = NULL;
  // keep track of the last node,
  // so when a new one is created, it is possible to link the last one to the new one
  last = first;

  // all the nodes that are not the head node, require a previous node to link to it
  // but none of the nodes require a next node. It can have, but it is not mandatory
  for (i = 1; i < n; i++)
  {
    t = new Node;
    t->data = a[i];
    t->next = NULL;

    // link the last node with the new one
    // to create a new node, it is necessary that the last node points to the new one
    last->next = t;
    last = t;
  }

  return first;
}

int count_nodes(struct Node *first)
{
  struct Node *cur_node = first;

  int count = 0;
  while (cur_node != NULL)
  {
    count++;
    cur_node = cur_node->next;
  }

  return count;
}

int count_recursively(struct Node *n)
{
  if (n == NULL)
    return 0;
  return count_recursively(n->next) + 1;
}

int add(struct Node *n)
{
  int sum = 0;
  if (n != NULL)
  {
    sum += n->data;
    return add(n->next) + sum;
  }

  return 0;
}

int max_n(struct Node *n)
{
  int max = INT_MIN;
  while (n)
  {
    if (n->data > max)
      max = n->data;
    n = n->next;
  }
  return max;
}

int RMax_n(struct Node *n)
{
  int x = 0;
  if (!n)
    return INT_MIN;
  x = RMax_n(n->next);
  return x > n->data ? x : n->data;
}

struct Node *search(struct Node *n, int e)
{
  if (!n)
    return NULL;

  if (n->data == e)
    return n;

  return search(n->next, e);
}

struct Node *first;
struct Node *perfomant_search(struct Node *n, int e)
{
  struct Node *previous = NULL;

  while (n)
  {
    if (n->data == e)
    {
      // move to front operation
      previous->next = n->next;
      n->next = first;
      first = n;
      return n;
    }
    previous = n;
    n = n->next;
  }

  return NULL;
}

struct Node *r_search(struct Node *n, int e)
{
  if (!n)
    return NULL;
  if (n->data == e)
    return n;
  return r_search(n->next, e);
}

void *insert_first(struct Node *n, int e)
{
  struct Node *nnode = new Node;
  nnode->data = e;
  nnode->next = n;
  n = nnode;
}

void insert_at(struct Node *n, int at, int e)
{
  int node_count = 0;

  for (int i = 0; i < at - 1; i++)
    n = n->next;

  struct Node *nnode = new Node;
  nnode->data = e;
  nnode->next = n->next;
  n->next = nnode;
}

void insert(struct Node *&first, int pos, int x)
{
  struct Node *t, *p;

  if (pos == 0)
  {
    t = new Node;
    t->data = x;
    t->next = first;
    first = t;
  }
  else if (pos > 0)
  {
    p = first;
    for (int i = 0; i < pos - 1 && pos; i++)
      p = p->next;

    if (p)
    {
      t = new Node;
      t->data = x;
      t->next = p->next;
      p->next = t;
    }
  }
}

// not possible to perform binary search
// linear search only
void linked_lists()
{

  struct Node *p_first;
  p_first = new Node;
  p_first->data = 5;
  p_first->next = new Node;
  p_first->next->data = 10;
  p_first->next->next = new Node;
  p_first->next->next->data = 15;
  p_first->next->next->next = NULL;

  Node *next_node = p_first;
  display_nodes(p_first);
  std::cout << "-------------" << "\n";
  int nodes = count_linked_list_nodes(p_first);
  std::cout << "Node count: " << nodes << std::endl;

  // iterate linked list with loops
  std::cout << "-------------" << "\n";
  struct Node *next_node3 = p_first;
  while (next_node3 != NULL)
  {
    std::cout << next_node3->data << std::endl;
    next_node3 = next_node3->next;
  }

  std::cout << "-------------" << "\n";
  int lst[5] = {1, 2, 3, 4, 5};

  struct Node *p_to_LL = create_linked_list(lst, 5);
  // struct Node *p_to_LL_ref = p_to_LL;
  while (p_to_LL != NULL)
  {
    std::cout << p_to_LL->data << std::endl;
    p_to_LL = p_to_LL->next;
  }

  std::cout << "-------------" << "\n";
  int lst2[5] = {15, 2, 3, 4, 5};
  struct Node *p_to_LL2 = create_linked_list(lst2, 5);
  display_nodes(p_to_LL2);
  std::cout << "-------------" << "\n";
  int lst3[5] = {15, 2, 3, 4, 5};
  struct Node *p_to_LL3 = create_linked_list(lst2, 5);
  recursive_display(p_to_LL3);
  std::cout << "-------------" << "\n";
  backwards_recursive_display(p_to_LL3);

  int lst5[10] = {15, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  struct Node *p_to_LL5 = create_linked_list(lst5, 10);
  std::cout << "Count with while: " << count_nodes(p_to_LL5) << std::endl;
  std::cout << "Count with recursion: " << count_recursively(p_to_LL5) << std::endl;

  int sum_of_ll = add(p_to_LL5);
  std::cout << "sum: " << sum_of_ll << "\n";

  int lst6[6] = {7, 10, 65, 5, 0, -1};
  struct Node *p_toLL6 = create_linked_list(lst6, 6);

  std::cout << max_n(p_toLL6) << std::endl;
  std::cout << RMax_n(p_toLL6) << std::endl;
  std::cout << search(p_toLL6, 8) << std::endl;
  std::cout << r_search(p_toLL6, 65)->data << std::endl;
  // std::cout << perfomant_search(p_toLL6, 65) << std::endl;
  std::cout << "-------------" << "\n";
  display_nodes(p_toLL6);
  int lst7[6] = {0, 1, 2, 10, 5, 10};
  struct Node *n = create_linked_list(lst7, 6);
  std::cout << "-------------" << "\n";
  display_nodes(n);
  std::cout << "-------------" << "\n";
  insert_at(n, 3, 15);
  display_nodes(n);
  std::cout << "-------------" << "\n";
  int lla[6] = {0, 1, 2, 10, 5, 10};
  struct Node *llc = create_linked_list(lla, 6);
  insert(llc, 0, 25);
  display_nodes(llc);

  delete p_first;
  // delete p_to_LL;
  // p_to_LL_ref = nullptr;
}
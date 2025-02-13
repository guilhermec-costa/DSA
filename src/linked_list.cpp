#include <iostream>

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

  delete p_first;
  // delete p_to_LL;
  // p_to_LL_ref = nullptr;
}
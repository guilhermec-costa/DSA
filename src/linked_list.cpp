#include <iostream>
#include <limits>

struct Node
{
  int data;
  // pointer to a memory location, where another Node is stored
  // self-referential structure
  struct Node *next = nullptr;
}; // 4 bytes total

int count_linked_list_nodes(Node *n)
{
  if (!n->next)
    return 1;

  return count_linked_list_nodes(n->next) + 1;
};

void display_nodes(struct Node *n)
{
  if (!n)
    return;
  std::cout << n->data << std::endl;
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

void insert_first(struct Node *&first, int e)
{
  struct Node *nnode = new Node;
  nnode->data = e;
  nnode->next = first;
  first = nnode;
}

void insert_at(struct Node *n, int at, int e)
{
  struct Node *p = n;

  for (int i = 0; i < at - 1; i++)
    p = p->next;

  struct Node *nnode = new Node;
  nnode->data = e;
  nnode->next = p->next;
  p->next = nnode;
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

struct Node *fst_for_deletion = NULL;
int delete_at(struct Node *p, int pos)
{
  int x;
  if (pos == 0)
  {
    fst_for_deletion = p->next;
    x = p->data;
    delete p;
    p = nullptr;
  }
  else
  {
    struct Node *q = NULL;
    for (int i = 0; i < pos && p; i++)
    {
      q = p;
      p = p->next;
    }

    q->next = p->next;
    x = p->data;
    delete p;
    p = nullptr;
  }

  return x;
}

struct Node *last_for_sorted = NULL;
bool is_sorted(struct Node *p)
{
  int max = INT_MIN;
  while (p != NULL)
  {
    if (p->data < max)
      return false;

    max = p->data;
    p = p->next;
  }

  return true;
}

void remove_duplicate_from_sorted(struct Node *p)
{
  struct Node *q = p->next;

  while (q != NULL)
  {
    if (p->data != q->data)
    {
      // sliding pointers
      p = q;
      q = q->next;
    }
    else
    {
      p->next = q->next;
      delete q;
      q = p->next;
    }
  }
}

struct Node *last = NULL;

// constant time O(1)
void append(int e)
{
  struct Node *t;

  t = new Node;
  t->data = e;
  t->next = NULL;
  last->next = t;
  last = t;
}

// not possible to perform binary search
// linear search only

// copy of the pointer. When dereferencing, it is possible to change the value
// but not possible to change the address, unless it is passed as reference
void change_adrr(int *&i)
{
  int *n = new int(20);
  i = n;
}

struct Node *fst;
void insert_sorted(struct Node *p, int e)
{
  struct Node *t, *q = NULL;
  t = new Node;
  t->data = e;
  t->next = NULL;

  while (p && p->data < e)
  {
    q = p;
    p = p->next;
  }

  if (p == fst)
  {
    t->next = fst;
    fst = t;
  }
  else
  {
    t->next = q->next;
    q->next = t;
  }
}

void reverse_links(struct Node *p, int l)
{
  struct Node *first = p;
  int aux[l] = {0};
  int i = 0;

  while (first != NULL)
  {
    aux[i++] = first->data;
    first = first->next;
  }

  // bring i back one position
  i--;
  while (p != NULL)
  {
    p->data = aux[i--];
    p = p->next;
  }
}

struct Node *first_for_reverse = NULL;
void reverse_sliding_pointers(struct Node *p)
{
  if (!first_for_reverse)
    first_for_reverse = p;

  struct Node *r = NULL, *q = NULL;

  while (p != NULL)
  {
    // sliding pointers
    // always prefer this method
    r = q;
    q = p;
    p = p->next;
    // reverse the link
    q->next = r;
  }

  // change the last node to be the first
  first_for_reverse = q;
}

struct Node *first_for_reverse_recursive;
void reverse_recursive(struct Node *p, struct Node *prev = NULL)
{
  if (!p)
  {
    first_for_reverse_recursive = prev;
    return;
  }

  struct Node *next = p->next;
  // reverse the link
  p->next = prev;
  reverse_recursive(next, p);
}

void concat(struct Node *f, struct Node *s)
{
  while (f->next != NULL)
    f = f->next;
  f->next = s;
}

// merge: combine two sorted list into a single sorted list
struct Node *merge(struct Node *f, struct Node *s)
{
  struct Node *new_linked_list = NULL, *last = NULL;
  if (f->data < s->data)
  {
    new_linked_list = last = f;
    f = f->next;
    last->next = NULL;
  }
  else
  {
    new_linked_list = last = s;
    s = s->next;
    last->next = NULL;
  }

  while (f && s)
  {
    if (f->data < s->data)
    {
      last->next = f;
      last = f;
      f = f->next;
      last->next = NULL;
    }
    else
    {
      last->next = s;
      last = s;
      s = s->next;
      last->next = NULL;
    }
  }

  if (f)
    last->next = f;
  else
    last->next = s;

  return new_linked_list;
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
  std::cout << "Inserting in first position" << "\n";
  insert_first(n, 45);
  display_nodes(n);
  std::cout << "-------------" << "\n";
  std::cout << "Inserting in third position" << "\n";
  insert_at(n, 3, 15);
  display_nodes(n);
  std::cout << "-------------" << "\n";
  int lla[6] = {0, 1, 2, 10, 5, 10};
  struct Node *llc = create_linked_list(lla, 6);
  insert(llc, 0, 25);
  display_nodes(llc);

  std::cout << "-------------" << "\n";
  int *i = new int(10);
  std::cout << "addr 1: " << i << "\n";
  change_adrr(i);
  std::cout << "addr 2: " << i << "\n";
  std::cout << "-------------" << "\n";
  std::cout << "Creating linked list by inserting" << "\n";
  struct Node *by_inserting = new Node;
  insert(by_inserting, 0, 5);
  insert(by_inserting, 1, 15);
  insert(by_inserting, 2, -50);
  insert(by_inserting, 0, 15);
  display_nodes(by_inserting);

  std::cout << "-------------" << "\n";
  std::cout << "Appending to linked list" << "\n";
  struct Node *first_node = new Node;
  first_node->data = 10;
  first_node->next = NULL;
  last = first_node;
  append(15);
  append(20);
  display_nodes(first_node);
  std::cout << "-------------" << "\n";
  std::cout << "Inserting in sorted linked list" << "\n";
  int x[6] = {0, 1, 2, 10, 18, 26};
  struct Node *xn = create_linked_list(x, 6);
  insert_sorted(xn, 19);
  insert_sorted(xn, 5);
  display_nodes(xn);
  std::cout << "-------------" << "\n";
  std::cout << "Deleting third idx from linked list" << "\n";
  fst_for_deletion = xn;
  delete_at(fst_for_deletion, 3);
  display_nodes(fst_for_deletion);
  std::cout << "-------------" << "\n";
  int deleted = delete_at(fst_for_deletion, 1);
  display_nodes(fst_for_deletion);
  std::cout << "-------------" << "\n";
  std::cout << deleted << "\n";

  int y[6] = {-1, 1, 2, 3, 4, 5};
  struct Node *yn = create_linked_list(y, 6);
  std::cout << "-------------" << "\n";
  std::cout << "Checking if is sorted" << "\n";
  std::cout << is_sorted(fst_for_deletion) << std::endl;
  std::cout << is_sorted(yn) << std::endl;
  std::cout << "-------------" << "\n";
  std::cout << "Removing duplicates from sorted linked list" << "\n";
  int z[11] = {1, 2, 2, 3, 4, 5, 5, 6, 9, 9, 10};
  struct Node *zn = create_linked_list(z, 11);
  remove_duplicate_from_sorted(zn);
  display_nodes(zn);
  std::cout << "-------------" << "\n";
  std::cout << "Reversing linked list" << "\n";
  reverse_links(zn, 11);
  display_nodes(zn);
  std::cout << "-------------" << "\n";
  std::cout << "Reversing linked list with sliding pointers" << "\n";
  first_for_reverse = zn;
  reverse_sliding_pointers(first_for_reverse);
  display_nodes(first_for_reverse);
  std::cout << "-------------" << "\n";
  reverse_sliding_pointers(first_for_reverse);
  display_nodes(first_for_reverse);
  std::cout << "-------------" << "\n";
  std::cout << "Reversing linked list with recursion" << "\n";
  first_for_reverse_recursive = zn;
  reverse_recursive(first_for_reverse_recursive);
  display_nodes(first_for_reverse_recursive);
  std::cout << "-------------" << "\n";
  std::cout << "Concatenating 2 linked lists" << "\n";
  int m[3] = {1, 2, 3};
  struct Node *lm = create_linked_list(m, 3);
  int b[3] = {4, 5, 6};
  struct Node *ln = create_linked_list(b, 3);
  concat(lm, ln);
  display_nodes(lm);
  std::cout << "-------------" << "\n";
  std::cout << "Merging 2 linked lists" << "\n";
  int g[3] = {1, 2, 3};
  struct Node *lg = create_linked_list(g, 3);
  int h[3] = {4, 5, 6};
  struct Node *lh = create_linked_list(h, 3);
  struct Node *merged = merge(lg, lh);
  display_nodes(merged);
  delete p_first;
  // delete p_to_LL;
  // p_to_LL_ref = nullptr;
}
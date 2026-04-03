#include "../include/doubly_linked_list.h"
#include <cstdio>

DoublyLL create_doubly_ll(int arr[], int l) {
  if (l == 0)
    return {};

  Node *HEAD = new Node{arr[0]};
  Node *TAIL = HEAD;

  for (int i = 1; i < l; i++) {
    Node *n = new Node{arr[i]};
    TAIL->next = n;
    n->prev = TAIL;
    TAIL = n;
  }

  return {HEAD, TAIL};
}

// static int length

void insert_doubly_ll(Node *&HEAD, int val, int index) {
  Node *node = new Node{val};

  if (index == 0) {
    HEAD->prev = node;
    node->next = HEAD;
    HEAD = node;
    return;
  }

  Node *p = HEAD;
  for (int i = 0; i < index; i++) {
    p = p->next;
  }

  node->next = p->next;
  node->prev = p;
  if (p->next)
    p->next->prev = node;

  p->next = node;
}

void delete_doubly_ll(Node *&HEAD, int index) {
  if (index < 0)
    return;

  if(!HEAD) return;

  Node *cp = HEAD;
  if (index == 0) {
    HEAD = HEAD->next;
    if(HEAD) HEAD->prev = nullptr;
    delete cp;
    return;
  }

  for(int i=0;i<index;i++) {
    cp = cp->next;
  }

  cp->prev->next = cp->next;

  if(cp->next) {
    cp->next->prev = cp->prev;
  }

  delete cp;
}

void reverse_ll(Node*& head) {
  if(!head) {
    printf("Head is null\n");
    return;
  }

  Node* p = head, *tmp = nullptr;

  while(p) {
    tmp = p->next;
    p->next = p->prev;
    p->prev = tmp;
    p = p->prev;

    if(p && !p->next) {
      head = p;
    }
  }
}

static void display_forward(Node *head) {
  while (head) {
    printf("%d - ", head->val);
    head = head->next;
  }
}

static void display_backward(Node *tail) {
  while (tail) {
    printf("%d - ", tail->val);
    tail = tail->prev;
  }
}

void doubly_linked_list() {
  int arr[] = {1, 2, 3, 4};
  auto list = create_doubly_ll(arr, 4);
  display_forward(list.HEAD);
  printf("\n");
  display_backward(list.TAIL);
  printf("\n");
  insert_doubly_ll(list.HEAD, 10, 3);
  display_forward(list.HEAD);
  delete_doubly_ll(list.HEAD, 0);
  printf("\n");
  display_forward(list.HEAD);
  reverse_ll(list.HEAD);
  printf("here");
  printf("\n");
  display_forward(list.HEAD);
};
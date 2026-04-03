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

static void display_forward(Node *head) {
  while (head) {
    printf("%d - ", head->val);
    head = head->next;
  }
}

static void display_backward(Node* tail) {
  while(tail) {
    printf("%d - ", tail->val);
    tail = tail->prev;
  }
}

void doubly_linked_list() {
  int arr[] = { 1, 2, 3, 4};
  auto list = create_doubly_ll(arr, 4);
  display_forward(list.HEAD);
  printf("\n");
  display_backward(list.TAIL);
  printf("\n");
};
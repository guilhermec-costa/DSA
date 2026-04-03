struct Node {
  Node *prev = nullptr;
  int val;
  Node *next = nullptr;
  Node(int val) : val(val) {}
  Node(int val, Node *prev, Node *next) : val(val), prev(prev), next(next) {}
};

struct DoublyLL {
  Node *HEAD = nullptr;
  Node *TAIL = nullptr;
};

DoublyLL create_doubly_ll(int arr[], int l);
void insert_doubly_ll(Node *&HEAD, int val, int index);
void doubly_linked_list();
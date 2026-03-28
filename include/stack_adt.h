class Stack {
public:
  int size = 0;
  int *stack;
  int top;

public:
  Stack(int size);
  ~Stack();
  bool is_empty();
  bool is_full();
  void push(int x);
  int pop();
  int peek(int i);
  void view();
  int stacktop();
};

class MyStackADT {
private:
  int _top = -1;
  int _size = 0;
  int *buf;

public:
  MyStackADT(int size);
  ~MyStackADT();
  void push(int key);
  void display();
  int pop();
  int peek(int index);
  inline int stacktop() {
    if (is_empty())
      return -1;
    return buf[_top];
  };
  bool is_empty();
  bool is_full();
  inline int size() { return _size; }
};

struct ListNode {
  int val;
  ListNode *next;

  ListNode(int val) : val(val), next(nullptr) {}
};

class StackLL {
  ListNode *_top = nullptr;
  int _size = 0;

public:
  StackLL() {};
  ~StackLL();
  void push(int key);
  inline bool is_empty() { return !_top; };
  void display();
  int peek(int position);
  int stacktop();
  int pop();
};
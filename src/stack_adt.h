class Stack
{
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
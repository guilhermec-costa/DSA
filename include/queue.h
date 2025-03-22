#include <memory>
// FIFO Discipline
// 2 ENDS: frontend and rearend
// insertion is done at rear end | deletion is done at frontend
// this way, deletion and insertion is O1 (constant)
// circular queues deals with some problems:
// 1 - dequeued slots can not be reutilized
// 2 - each slot can only be used one time
// 3 - queue can be empty and full at the sime time (rear at arrays size - 1 && front in the same position as rear)

// (rear + 1) % size
class Queue
{
private:
  // Data
  int *Q;
  int size;
  int front;
  int rear;

public:
  Queue(int size);
  ~Queue();
  // operations
  void display();
  void displayCircular();
  void enqueue(int x);
  void circularEnqueue(int x);
  int circularDequeue();
  int dequeue();
  bool isEmpty();
  bool isFull();
  int first;
  int last;
};
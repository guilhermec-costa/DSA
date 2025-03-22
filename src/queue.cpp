#include "queue.h"
#include <iostream>

void Queue::enqueue(int e)
{
  if (this->isFull())
  {
    std::cout << "Queue is full\n";
    return;
  }

  this->Q[++this->rear] = e;
}

void Queue::circularEnqueue(int x)
{
  // full condition: when next rear position would be at the same position as front
  if ((this->rear + 1) % this->size == this->front)
  {
    std::cout << "Queue is full\n";
  }
  else
  {
    this->rear = (this->rear + 1) % this->size;
    this->Q[rear] = x;
  }
}

int Queue::circularDequeue()
{
  int x = -1;
  // empty condition: when rear is at the same position as front
  if (this->rear == this->front)
  {
    std::cout << "Queue is empty\n";
  }
  else
  {
    this->front = (this->front + 1) % this->size;
    x = this->Q[this->front];
  }
  return x;
}

int Queue::dequeue()
{
  int x = -1;
  if (this->isEmpty())
  {
    std::cout << "Queue is empty\n";
  }
  x = this->Q[this->front++];
  this->Q[this->front] = -1;
  return x;
}

bool Queue::isFull()
{
  return this->rear == this->size - 1;
}

bool Queue::isEmpty()
{
  return this->rear == this->front;
}

Queue::Queue(int size)
{
  // for circular queues, both should be at index 0
  this->front = this->rear = -1;
  this->size = size;
  this->Q = new int[size]{0};
}

Queue::~Queue()
{
  delete this->Q;
}

void Queue::display()
{
  for (int i = this->front + 1; i <= this->rear; i++)
  {
    int e = this->Q[i];
    std::cout << e << "\n";
  }
}

void Queue::displayCircular()
{
  int pos = this->front + 1;

  do
  {
    std::cout << this->Q[pos] << "\n";
    pos = (this->front + 1) % this->size;
  } while (pos != (this->rear + 1) % this->size);
}

void queues()
{
  int space[7] = {};
  Queue q1 = Queue(7);
  q1.enqueue(5);
  q1.enqueue(10);
  q1.enqueue(15);
  q1.display();
  q1.dequeue();
  std::cout << "-----" << std::endl;
  q1.display();
}
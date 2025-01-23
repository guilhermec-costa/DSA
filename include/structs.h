#pragma once
// declared in stack
struct Rect
{

public:
  int wid;
  int hei;

  int perimeter()
  {
    return (this->wid * 2) + (this->hei * 2);
  }
};

// definition
typedef struct Author
{
  char firstName[56];
  char lastName[56];
} author;

typedef struct Actress
{
  char firstName[56];
  char lastName[56];
} acctress;
#include "../include/stack_adt.h"
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>

bool is_operand(char x) {
  if (x == '+' || x == '-' || x == '*' || x == '/')
    return false;
  return true;
}

int precedence(char x) {
  if (x == '+' || x == '-') {
    return 1;
  }

  if (x == '*' || x == '/') {
    return 2;
  }

  return 0;
}

char *convert(char *infix) {
  StackLL st;
  char *postfix = (char *)(malloc(strlen(infix) + 1));
  int i = 0, j = 0;
  while (infix[i] != '\0') {
    if (is_operand(infix[i])) {
      postfix[j++] = infix[i++];
    } else {
      if (precedence(infix[i]) > precedence(st.stacktop())) {
        st.push(infix[i++]);
      } else {
        postfix[j++] = st.pop();
      }
    }
  }
  while (!st.is_empty())
    postfix[j++] = st.pop();

  postfix[j] = '\0';
  return postfix;
}

int operate(int x1, int x2, char op) {
  switch (op) {
  case '+':
    return x1 + x2;
  case '-':
    return x1 - x2;
  case '*':
    return x1 * x2;
  case '/':
    return x1 / x2;
  }
  return 0;
}
/*
  is it operand? push to the stack
  is it operator? pop out the last two elements of stack, and calculate the
    operation. The result of the operation is pushed to the stack
  the operation is as follows:
    { second el. popped } { operator } { first el. popped }

  keep doing this until finish the postfix expression. The last value on stack
  is the result
*/
int evaluate_postfix(char *postfix) {
  StackLL st;
  int i, x1, x2, r;
  for (i = 0; i < postfix[i] != '\0'; i++) {
    if (is_operand(postfix[i])) {
      // {char} - '0' gives the numeric value from 0 to 9
      st.push(postfix[i] - '0');
    } else {
      x2 = st.pop();
      x1 = st.pop();
      st.push(operate(x1, x2, postfix[i]));
    }
  }
  return st.pop();
}

/* stack method
  for each character on the expr:
  is it operand? push to postfix
  is it operator? check precedence.
    If it is greater than to the last operator's precedence on the stack,
    push it to the stack and continue to the next char in the expr. Otherwise
  (less then or equal to), pop the top of the stack, and the popped operator
  goes to the postfix. Keep doing this pop/push procedure until the operator can
  be pushed to the stack. Only after pushing it to the stack, move to the next
  element on the expr

  after reaching the end of the expr, you must pop the rest of the elements from
  the stack, and push them into the postfix
*/

/* x = 6 + 5 + 3 * 4
  with precedence -> x = ((6 + 5) + (3 * 4))

  precedence and associativity do not directly determine the execution order of
  the operations

  x65+34*+= -> this is the POSTFIX form (Reverse Polish Notation - RPN)
  this postfix form is what is used on the evaluation process
  6 + 5 happens before 3 * 4 on the stack. So it means the precedence is
  important to assemble the postfix form, not important to the order of
  operations.
*/

void infix_to_postfix() {
  printf("Infix to postfix\n");
  char *expr = (char *)"a+b*c-d/e\0";

  // (a+[bc*]-d/e)
  // (a+[bc*]-[de/])
  // ([abc*+]-[de/])
  // abc*+de/-
  char *reverse_notation = convert(expr);
  printf("Reverse notation: %s\n", reverse_notation);

  char *expr2= (char *)"1+2*3-3/5\0";
  printf("result: %d\n", evaluate_postfix(expr2));
}
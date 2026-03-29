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
void infix_to_postfix() {
  printf("Infix to postfix\n");
  char *expr = (char *)"a+b*c-d/e\0";

  // (a+[bc*]-d/e)
  // (a+[bc*]-[de/])
  // ([abc*+]-[de/])
  // abc*+de/-
  char *reverse_notation = convert(expr);
  printf("Reverse notation: %s\n", reverse_notation);
}
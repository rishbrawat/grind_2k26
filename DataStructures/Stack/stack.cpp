/*
   stack is a linear data structure that stores element in a linear fashion. unlike arrays or vectors we can't perform random access, instead we only access the most recently inserted element.

   stack follows LIFO property.
   LIFO: last in first out -> the element thats added last will be removed first
      ex. books placed at the top of each other

   stack properties:
      top: points to the last element
      every operation happens at the top
      if top changes incorrectly the stack breaks
      if the stack is empty top = -1
      if stack has elements it will point to the top element

   operations
      push: at the top of the stack
      pop: at the top of the stack
      peek/top: reads the top element without removing it
      isEmpty: checks if stack is empty
      isFull: checks if stack is full
*/

#include<iostream>
using namespace std;

#define MAX 5 

struct Stack {
   int arr[MAX];
   int top;
};

int isEmpty(struct Stack *s) {
   return s->top == -1;
}
int isFull(struct Stack *s) {
   return s->top == MAX-1;
}

void push(struct Stack* s, int val) {
   if(isFull(s)) {
      cout << "stack overflow!\n";
      return;
   }
   s->top++;
   s->arr[s->top] = val;
}

int pop(struct Stack* s){
   if(isEmpty(s)) {
      cout << "stack underflow!\n";
      return -1;
   }
   return s->arr[s->top--];
}

int peek(struct Stack *s) {
   if(isEmpty(s)) {
      cout << "stack is empty!\n";
      return -1;
   }
   return s->arr[s->top];
}

int main() {
   struct Stack* s = new Stack;
   push(s, 10);
   cout << s->arr[s->top];
}
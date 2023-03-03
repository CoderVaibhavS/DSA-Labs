#ifndef STACK_H
#define STACK_H

#include "Element.h"
#include "bool.h"

typedef struct Stack Stack;

Stack *newStack();

bool push(Stack *stack, Element element);

Element *top(Stack *stack);

bool pop(Stack *stack);

bool isEmpty(Stack *stack);

void freeStack(Stack *stack);

#endif
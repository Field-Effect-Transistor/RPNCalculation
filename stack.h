#pragma once
#include "stdbool.h"

#include "stack.c"

#define UINT unsigned int

// struct realization of stack
struct Stack;

// pop -- remove top element from stack
bool pop(struct Stack* stack, UINT* data);

// push -- add element to top of stack
bool push(struct Stack* stack, UINT data);
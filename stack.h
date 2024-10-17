#pragma once
#include "stdbool.h"

#include "stack.c"

/**
 * @struct Stack
 * @brief Represents a stack data structure.
 *
 * The Stack struct is used to implement a stack data structure. It contains the following fields:
 * - size: The maximum size of the stack.
 * - top: The index of the top element in the stack.
 * - arr: An array that stores the elements of the stack.
 */
struct Stack;

/**
 * Pushes an element onto the stack.
 *
 * @param stack The stack to push to.
 * @param data The element to push.
 * @return true if the element was successfully pushed, false if the stack is full.
 */
bool pop(struct Stack* stack, int* data);

/**
 * Pops an element from the stack.
 *
 * @param stack The stack to pop from.
 * @param data The popped element is stored here.
 * @return true if the element was successfully popped, false if the stack is empty.
 */
bool push(struct Stack* stack, int data);
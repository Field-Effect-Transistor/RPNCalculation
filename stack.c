#include "stack.h"

#define UINT unsigned int

struct Stack {
    int size;
    int top;
    UINT* arr;
};

bool push(struct Stack* stack, UINT data) {
    if (stack->top == stack->size - 1) {
        return false;
    }
    stack->top++;
    stack->arr[stack->top] = data;
    return true;
}

bool pop(struct Stack* stack, UINT* data) {
    if (stack->top == -1) {
        return false;
    }
    *data = stack->arr[stack->top];
    stack->top--;
    return true;
}

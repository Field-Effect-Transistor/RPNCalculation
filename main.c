#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

#define SIZE 128

int main(void) {
    struct Stack stack;
    { //stack initialization
        stack.size = SIZE;
        stack.top = -1;
        stack.arr = (int*)calloc(SIZE, sizeof(int));
    }
    printf("Acceptable operations: + - * /\n");
    printf("");

    free(stack.arr);
    return 0;
}

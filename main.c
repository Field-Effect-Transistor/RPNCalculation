#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

#define SIZE 128
#define UINT unsigned int

int main(void) {
    struct Stack stack;
    { //stack initialization
        stack.size = SIZE;
        stack.top = -1;
        stack.arr = (UINT*)calloc(SIZE, sizeof(UINT));
    }

    if(stack.arr == NULL) {
        printf("Failed to allocate memory for stack\n");
        return 1;
    }

    printf("Acceptable operations: + - * /\n");
    printf("Enter expression: ");
    char* e = (char*)calloc(8 * SIZE, sizeof(char));
    
    if(e == NULL) {
        printf("Failed to allocate memory for expression\n");
        return 1;
    }
    
    scanf("%s", e);

    for(char* curr = e; *curr != '\0'; ++curr) {
        if(*curr == '+' || *curr == '-' || *curr == '*' || *curr == '/') {
            UINT arg1, arg2;
            if(!pop(&stack, &arg1) || !pop(&stack, &arg2)) {
                printf("Stack is empty\n");
                return 2;
            }

            switch(*curr) {
                case '+':
                    if(!push(&stack, arg1 + arg2)) {
                        printf("Stack overflow");
                        return 3;
                    }
                    break;
                case '-':
                    if(!push(&stack, arg1 - arg2)) {
                        printf("Stack overflow");
                        return 3;
                    }
                    break;
                case '*':
                    if(!push(&stack, arg1 * arg2)) {
                        printf("Stack overflow");
                        return 3;
                    }
                    break;
                case '/':
                    if(!push(&stack, arg1 / arg2)) {
                        printf("Stack overflow");
                        return 3;
                    }
                    break;
                default:
                    printf("Unsupported operation. How did you even get here? =)\n");
                    return 4;
                    break;
            }
        } else if (*curr >= '0' && *curr <= '9') {
            if (!push(&stack, *curr - '0')) {
                printf("Stack overflow");
                return 3;
            }
        } else {
            printf("Invalid expression: unsupported character\n");
            return 5;
        }
            
    }

    printf("Result: %u\n", stack.arr[stack.top]);

    free(stack.arr);
    free(e);
    return 0;
}

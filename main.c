#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "stack.h"

#define SIZE 128
#define UINT unsigned int

int main(void) {
    struct Stack stack; // Declare a stack structure
    { // Stack initialization
        stack.size = SIZE; // Set the stack size
        stack.top = -1; // Initialize the stack top to -1 (indicating an empty stack)
        stack.arr = (UINT*)calloc(SIZE, sizeof(UINT)); // Allocate memory for the stack array
    }

    // Check for successful memory allocation
    if(stack.arr == NULL) {
        printf("Failed to allocate memory for stack\n");
        return 1; // Exit the program if memory allocation fails
    }

    // Instructions for the user
    printf("Acceptable operations: + - * / ^\n");
    printf("Enter expression: ");
    
    // Allocate memory for the expression string
    char* e = (char*)calloc(8 * SIZE, sizeof(char));

    // Check for successful memory allocation for the expression
    if(e == NULL) {
        printf("Failed to allocate memory for expression\n");
        return 1; // Exit the program if memory allocation fails
    }
    
    // Read the expression from input
    fgets(e, 8 * SIZE, stdin);
    
    // Remove the newline character if present
    for(char* curr = e; *curr != '\0'; ++curr) {
        if(*curr == '\n') {
            *curr = '\0'; // Replace newline with null terminator
            break;
        }
    }

    // Process each character in the expression
    for(char* curr = e; *curr != '\0'; ++curr) {
        // Check if the current character is an operator
        if(*curr == '+' || *curr == '-' || *curr == '*' || *curr == '/' || *curr == '^') {
            UINT arg1, arg2; // Variables to hold the operands
            // Pop two operands from the stack
            if(!pop(&stack, &arg1) || !pop(&stack, &arg2)) {
                printf("Stack is empty\n");
                return 2; // Exit if the stack is empty
            }

            // Perform the operation based on the current operator
            switch(*curr) {
                case '+':
                    if(!push(&stack, arg1 + arg2)) {
                        printf("Stack overflow");
                        return 3; // Exit if stack overflow occurs
                    }
                    break;
                case '-':
                    if(!push(&stack, arg2 - arg1)) {
                        printf("Stack overflow");
                        return 3; // Exit if stack overflow occurs
                    }
                    break;
                case '*':
                    if(!push(&stack, arg1 * arg2)) {
                        printf("Stack overflow");
                        return 3; // Exit if stack overflow occurs
                    }
                    break;
                case '/':
                    if (!arg1) { // Check for division by zero
                        printf("Error: Division by zero\n");
                        return 6; // Exit if division by zero
                    }
                    if(!push(&stack, arg2 / arg1)) {
                        printf("Stack overflow");
                        return 3; // Exit if stack overflow occurs
                    }
                    break;
                case '^':
                    if(!push(&stack, pow(arg2, arg1))) {
                        printf("Stack overflow");
                        return 3; // Exit if stack overflow occurs
                    }
                    break;
                default:
                    printf("Unsupported operation. How did you even get here? =)\n");
                    return 4; // Exit for unsupported operations
            }
        } 
        // Check if the current character is a digit
        else if (*curr >= '0' && *curr <= '9') {
            if (!push(&stack, *curr - '0')) { // Convert char to int and push onto the stack
                printf("Stack overflow");
                return 3; // Exit if stack overflow occurs
            }
        } 
        // Handle unsupported characters
        else {
            printf("Invalid expression: unsupported character: %c\n", *curr);
            return 5; // Exit for invalid characters
        }
    }

    // Output the result from the top of the stack
    printf("Result: %u\n", stack.arr[stack.top]);

    // Free allocated memory
    free(stack.arr);
    free(e);
    return 0;
}

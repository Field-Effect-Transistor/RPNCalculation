#include "rpn.h"

//size of stack
#define SIZE 16
//number of digits in number + 1 for /0
#define nSIZE 11

int rpn(char* expression, int* result) {
    struct Stack stack; // Declare a stack structure
    { // Stack initialization
        stack.size = SIZE; // Set the stack size
        stack.top = -1; // Initialize the stack top to -1 (indicating an empty stack)
        stack.arr = (int*)calloc(SIZE, sizeof(int)); // Allocate memory for the stack array
    }

    // Check for NULL pointer
    if(expression == NULL) {
        printf("Failed to allocate memory for expression\n");
        return 1; // Exit the program if memory allocation fails
    }

    // Check for successful memory allocation
    if(stack.arr == NULL) {
        printf("Failed to allocate memory for stack\n");
        return 1; // Exit the program if memory allocation fails
    }

    char num[nSIZE] = "";
    for(int i = 0; i < nSIZE; ++i) {
        num[i] = '\0';
    }

    // Process each character in the expression
    for(char* curr = expression; *curr != '\0'; ++curr) {
        // Check if the current character is an operator
        if( // Arithmetic operators
            *curr == '+' || *curr == '-' ||
            *curr == '*' || *curr == '/' ||
            *curr == 'p' || *curr == '%' ||
            // Bitwise operators
            *curr == '&' || *curr == '|' ||
            *curr == '^' || *curr == '~' ||
            *curr == '<' || *curr == '>' ||
            // Comparison operators
            *curr == '=' || *curr == '!') {
            int arg1, arg2; // Variables to hold the operands
            // Pop two operands from the stack
            if(!pop(&stack, &arg1)) {
                printf("Stack underflow\n");
                return 2; // Exit if the stack is empty
            }

            if(*curr != '~') {
                if(!pop(&stack, &arg2)) {
                    printf("Stack underflow\n");
                    return 2; // Exit if the stack is empty
                }
            }

            // Perform the operation based on the current operator
            switch(*curr) {
                case '+':
                    if(curr[1] == '+') {
                        push(&stack, arg2);
                        push(&stack, ++arg1);  
                        ++curr; //restore curr                    
                    } else {
                        push(&stack, arg1 + arg2);
                    }
                    break;
                case '-':
                    if(curr[1] == '-') {
                        push(&stack, arg2);
                        push(&stack, --arg1);
                        ++curr; //restore curr
                    } else {
                        push(&stack, arg2 - arg1);
                    }
                    break;
                case '*':
                    push(&stack, arg1 * arg2);
                    break;
                case '/':
                    if (!arg1) { // Check for division by zero
                        printf("Error: Division by zero\n");
                        return 6; // Exit if division by zero
                    }
                    push(&stack, arg2 / arg1);
                    break;
                case 'p':
                    push(&stack, pow(arg2, arg1));
                case '%':
                    if (!arg1) { // Check for division by zero
                        printf("Error: Division by zero\n");
                        return 6; // Exit if division by zero
                    }
                    push(&stack, arg2 % arg1);
                    break;
                case '&':
                    ;push(&stack, arg1 & arg2);
                    break;
                case '|':
                    push(&stack, arg1 | arg2);
                    break;
                case '^':
                    push(&stack, arg1 ^ arg2);
                    break;
                case '~':
                    push(&stack, ~arg1);
                    break;
                case '<':
                    if(curr[1] == '<') {
                        push(&stack, arg2 << arg1);
                        ++curr; //restore the curr pointer
                    } else if(curr[1] == '=') {
                        push(&stack, arg2 <= arg1);
                        ++curr; //restore the curr pointer
                    } else {
                        push(&stack, arg2 < arg1);
                    }
                    break;
                case '>':
                    if(curr[1] == '>') {
                        push(&stack, arg2 >> arg1);
                        ++curr; //restore the curr pointer
                    } else if(curr[1] == '=') {
                        push(&stack, arg2 >= arg1);
                        ++curr; //restore the curr pointer
                    } else {
                        push(&stack, arg2 > arg1);
                    }
                    break;
                case '=':
                    if (curr[1] == '=') {
                        push(&stack, arg1 == arg2);
                        ++curr;
                    } else {
                        printf("Unsupported operation.\n");
                        return 4;
                    }
                    break;
                case '!':
                    if (curr[1] == '=') {
                        push(&stack, arg1 != arg2);
                        ++curr;
                    } else {
                        printf("Unsupported operation.\n");
                        return 4;
                    }
                    break;
                default:
                    printf("Unsupported operation. How did you even get here? =)\n");
                    return 4; // Exit for unsupported operations
            }
        } 
        // Check if the current character is a digit
        else if (*curr >= '0' && *curr <= '9') {
            for(; *curr >= '0' && *curr <= '9'; ++curr) {
                num[strlen(num)] = *curr;
            }

            if(!push(&stack, atoi(num))) {
                printf("Stack overflow");
                return 3; // Exit if stack overflow occurs
            }
            for(int i = 0; i < nSIZE; ++i) {
                num[i] = '\0';
            }

            --curr; // restore the curr pointer
        } 
        else if (*curr == ' ') {
            continue;
        }
        // Handle unsupported characters
        else {
            printf("Invalid expression: unsupported character: %c\n", *curr);
            return 5; // Exit for invalid characters
        }
    }

    *result = stack.arr[stack.top];
    if(stack.top > 0) {
        printf("Warning: stack has more then 1 element.\n");
    }

    // Free allocated memory
    free(stack.arr);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "rpn.h"

int main(void) {
    // Instructions for the user
    printf("For acceptable operations look at README.md\n");
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
    
    int result, status;
    if ((status = rpn(e, &result)) != 0) {
        free(e);
        return status;
    }
    
    // Output the result from the top of the stack
    printf("Result: %i\n", result);
    free(e);

    return 0;
}

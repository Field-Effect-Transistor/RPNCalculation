# Reverse Polish Notation (RPN) Calculator Using a Stack

This project implements a simple calculator using a stack to perform operations in [Reverse Polish Notation (RPN)](https://en.wikipedia.org/wiki/Reverse_Polish_notation). The program allows users to input arithmetic expressions, which are processed using stack operations.

## Program Description

The program reads a mathematical expression in RPN format and computes the result using a stack. It supports the following operations:
- Addition (`+`)
- Subtraction (`-`)
- Multiplication (`*`)
- Division (`/`)

### Features:
- Stack-based implementation for storing and processing operands.
- Handles single-digit numbers and basic arithmetic operations.
- Dynamic memory allocation for stack storage and input expression.
- Error handling for unsupported operations and stack overflow.

### Compilation and Usage:
1. **Prerequisites:**
   - A C compiler (like GCC).
   
2. **Compiling the program:**
   ```bash
   gcc main.c -o index.out
   ```

3. **Running the program:**
   ```bash
   ./index.out
   ```
   After running the program, input the expression in Reverse Polish Notation format (e.g., `23+`), where the operands precede the operators.

### Examples:
For the input `23+`, the program will compute:
```
2 + 3 = 5
```

### Error Handling:
- **Failed to allocate memory:** If memory allocation was failed, the program will display an error message and exit with `error code 1`.
- **Empty Stack:** If an operation is attempted without sufficient operands, the program will display a "Stack is empty" error and exit with `error code 2`.
- **Stack Overflow:** If too many operands are pushed to the stack, the program will notify the user of a stack overflow and exit with `error code 3`.
- **Unsupported Operation:** If an unsupported operation is encountered, the program will display an error message and exit with `error code 4`.
- **Invalid expression:** If an invalid expression is encountered, the program will display an error message and exit with `error code 5`.


### File Structure:
- `main.c`: Contains the main function that processes input and performs stack operations.
- `stack.h` and `stack.c`: Define and implement stack functions like `push` and `pop`.

#pragma once

#include <math.h>
#include <string.h>

#include "rpn.c"

#include "stack.h"

/**
 * Evaluates a mathematical expression given in Reverse Polish Notation (RPN) and
 * stores the result in the variable pointed to by result.
 *
 * @param expression The RPN expression to evaluate.
 * @param result The result is stored in the variable pointed to by result.
 * @return 0 if the expression was successfully evaluated, otherwise an error code
 *         indicating the type of error that occurred.
 */
int rpn(char* expression, int *result);
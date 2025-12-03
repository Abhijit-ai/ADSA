## Infix to Postfix Conversion and Evaluation

### Problem Statement

This program demonstrates the conversion of an infix arithmetic expression to its equivalent postfix (Reverse Polish Notation) form and then evaluates the resulting postfix expression. This process is fundamental in compiler design and calculator implementations, as postfix expressions are easier for computers to parse and evaluate due to the absence of operator precedence rules and parentheses.

### Related Algorithms: Infix to Postfix Conversion and Postfix Evaluation

#### 1. Infix to Postfix Conversion

**Purpose:** To transform an expression from human-readable infix notation (e.g., `A + B * C`) to postfix notation (e.g., `A B C * +`), where operators appear after their operands.

**Algorithm (Shunting-Yard Algorithm concept):**
This algorithm primarily uses a **stack** to temporarily store operators and parentheses.

1.  **Initialize**: Create an empty `operator stack` and an empty `postfix expression string`.
2.  **Scan**: Read the infix expression token by token from left to right.
3.  **Process Tokens**:
    *   **Operand**: If the token is an operand (number or variable), append it directly to the `postfix expression string`.
    *   **Opening Parenthesis `(`**: Push it onto the `operator stack`.
    *   **Closing Parenthesis `)`**: Pop operators from the `operator stack` and append them to the `postfix expression string` until an opening parenthesis `(` is encountered. Pop and discard the `(`.
    *   **Operator**: If the token is an operator (e.g., `+`, `-`, `*`, `/`):
        *   While the `operator stack` is not empty, the top element is not `(`, and the current operator's precedence is less than or equal to the precedence of the operator at the top of the stack: pop the operator from the `operator stack` and append it to the `postfix expression string`.
        *   After the loop, push the current operator onto the `operator stack`.
4.  **Final Step**: After scanning the entire infix expression, pop any remaining operators from the `operator stack` and append them to the `postfix expression string` until the stack is empty.

**Operator Precedence (Typical):**
*   `*`, `/` (Multiplication, Division) have higher precedence than `+`, `-` (Addition, Subtraction).

#### 2. Postfix Expression Evaluation

**Purpose:** To compute the numerical result of an expression given in postfix notation.

**Algorithm:**
This algorithm uses an **operand stack** to store numbers and intermediate results.

1.  **Initialize**: Create an empty `operand stack`.
2.  **Scan**: Read the postfix expression token by token from left to right.
3.  **Process Tokens**:
    *   **Operand**: If the token is an operand (a number), convert it to its numeric value and push it onto the `operand stack`.
    *   **Operator**: If the token is an operator (e.g., `+`, `-`, `*`, `/`):
        *   Pop the top two operands from the `operand stack`. The first popped is `operand2`, and the second popped is `operand1`.
        *   Perform the arithmetic operation: `result = operand1 operator operand2`.
        *   Push the `result` back onto the `operand stack`.
4.  **Final Step**: After scanning the entire postfix expression, the final result will be the only element left on the `operand stack`. Pop this value.

### Code Details

The `q8.c` file implements both conversion and evaluation using a character array as a stack:

*   **Global Stack Variables**: `char stack[MAX]` and `int top = -1` define a global stack and its top pointer for operator storage during conversion.
*   **Stack Operations**:
    *   `push(char c)`: Pushes a character onto the stack.
    *   `pop()`: Pops and returns the top character from the stack.
    *   `peek()`: Returns the top character without popping.
    *   `isEmpty()`: Checks if the stack is empty.
*   **`precedence(char op)`**: A helper function that returns an integer representing the precedence of an operator. Higher number means higher precedence.
*   **`infixToPostfix(char infix[], char postfix[])`**:
    *   Takes an `infix` expression string and an empty `postfix` string as input.
    *   Iterates through the `infix` string, applying the rules described in the algorithm above to convert it.
    *   Uses the global `stack` for operators.
*   **`evaluatePostfix(char postfix[])`**:
    *   Takes a `postfix` expression string as input.
    *   Uses a separate integer stack (`valStack`) to store operand values during evaluation.
    *   Iterates through the `postfix` string. If an operand is encountered, it's pushed onto `valStack`. If an operator is encountered, two operands are popped, the operation is performed, and the result is pushed back.
    *   Returns the final result from the `valStack`.

The `main` function:
1.  Initializes a hardcoded `infix` expression string: `char infix[MAX] = "(3+4)*2";`.
2.  Prints the `infix` expression.
3.  Calls `infixToPostfix` to convert it to `postfix` form and prints the `postfix` expression.
4.  Calls `evaluatePostfix` to evaluate the `postfix` expression and prints the `result`.

### Sample Input/Output

**Input:**

The infix expression is hardcoded within the `main` function:
`char infix[MAX] = "(3+4)*2";`

**Output:**

```
Infix Expression: (3+4)*2
Postfix Expression: 34+2*
Evaluation Result: 14
```
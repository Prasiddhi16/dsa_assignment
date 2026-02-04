Documentataion for program 1:Balanced Parantheses Checker

(A)Data Structures Defined
-A global character array 'stack[max]'is defined.
-'MAX' is the maximum size of the stacl(20)
-top is an integer that tracks the state of stack
-only starting brackets are pushedin the stack

(B) Functions

    1:push(char ch)
    -checks for overflow
    -pushes the opening brackets to stack

    2:pop()
    -removes top element of the stack
    -check for underflow and return '\0'if empty
    
    3:balance(char *exp)
    -checks for balanced parantheses
    -loops through string
        -pushes opening brackets to stack
        -pops and verifies matching closing brackets
    -return -1 if balanced or 0

(C) The main() function
        -Defines an array of test expressions:
    - `"a + (b - c) * (d"`
    - `"m + [a - b * (c + d * {m)]"`
    - `"a + (b - c)"`  
    - Iterates through each expression:
    - Calls `balance()` to check if it is balanced.  
    - Prints the result (`balanced` or `not balanced`).

(D)Output

    Expressions: a + (b - c) * (d 
    The expression isn't balanced
    Expressions: m + [a - b * (c + d * {m)]
    The expression isn't balanced
    Expressions: a + (b - c)
    The expression is balanced



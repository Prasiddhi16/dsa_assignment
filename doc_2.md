Documentataion for program 1:Balanced Parantheses Checker

(A)Data Structures Defined
- A global character array stack[MAX] is defined for operator handling during infix-to-postfix conversion.
- A global integer array evalStack[MAX] is defined for evaluating the postfix expression.
- MAX is the maximum size of both stacks (20).
- top and evalTop are integer variables that track the state of the respective stacks.
- Operators and parentheses are pushed into stack, while numeric operands are pushed into evalStack.


(B) Functions

    1:push(char ch)
    - Pushes a character (operator or parenthesis) onto the operator stack.
    - No overflow check is implemented.

    2:pop()
    - Removes and returns the top element from the operator stack.
    - No underflow check is implement
     3:peek()
    - Returns the top element of the operator stack without removing it.

    
     4:precedence(char op)
    - Returns the precedence level of  an operator:
    - + and - gives 1
    - * and / gives 2
    - Others give 0

     5:infixToPostfix(char *infix, char *postfix)

    - Converts an infix expression to postfix using the Shunting Yard algorithm.
    - Loops through each character of the infix string:
    - Operands are directly appended to the postfix string.
    - Opening brackets are pushed to the stack.
    - Closing brackets cause popping until the matching opening bracket is found.
    - Operators are pushed or popped based on precedence.
    - Remaining operators in the stack are appended to the postfix string at the end.
     6:evalPush(int val)
    - Pushes an integer operand onto the evaluation stack.

    7:evalPop()
    - Pops and returns the top operand from the evaluation stack.

    8:evaluatePostfix(char *postfix)
    - Evaluates the postfix expression using a stack-based approach.
    - Loops through each character of the postfix string:
    - Operands are pushed to the evaluation stack.
    - Operators pop two operands, apply the operation, and push the result.
    -Return final result



(C) The main() function
       - Declares two character arrays: infix and postfix.
    - Prompts the user to enter an infix expression.
    - Calls infixToPostfix() to convert the expression.
    - Prints the resulting postfix expression.
    - Calls evaluatePostfix() to compute the result.
    - Prints the final evaluation result.

    (D) Output
   
   Enter infix expression: (9+8)*3     
    Postfix expression: 98+3*
    Evaluation result: 51




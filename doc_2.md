Documentation for program 2: Inficx to Postfix Conversion  

(A)Data Structures Defined  
- A global character array stack[MAX] is defined for operator handling during infix to postfix conversion  
- A global integer array evalStack[MAX] is defined for evaluating the postfix expression  
- MAX is the maximum size of both stacks (20)  
- top and evalTop are integer variables that track the state of the respective stacks  
- Operators and paranthesis are pushed into stack, while numeric operands are pushed into evalStack  

(B) Functions  

1:push(char ch)  
- pushes a character (operator or parenthesis) onto the operator stack  
- no overflow check is implement  

2:pop()  
- removes and returns the top element from the operator stack  
- no underflow check is implement  

3:peek()  
- returns the top element of the operator stack without removing it  

4:precedence(char op)  
- returns the precedence level of an operator  
- + and - gives 1  
- * and / gives 2  
- others give 0  

5:infixToPostfix(char *infix, char *postfix)  
- converts an infix expression to postfix using the shunting yard algorithm  
- loops through each character of the infix string  
- operands are directly appended to the postfix string  
- opening brackets are pushed to the stack  
- closing brackets cause popping until the matching opening bracket is found  
- operators are pushed or popped based on precedence  
- remaining operators in the stack are appended to the postfix string at the end  

6:evalPush(int val)  
- pushes an integer operand onto the evaluation stack  

7:evalPop()  
- pops and returns the top operand from the evaluation stack  

8:evaluatePostfix(char *postfix)  
- evaluates the postfix expression using a stack based approach  
- loops through each character of the postfix string  
- operands are pushed to the evaluation stack  
- operators pop two operands, apply the operation, and push the result  
- return final result  

(C) The main() function  
- declares two character arrays infix and postfix  
- prompts the user to enter an infix expression  
- calls infixToPostfix() to convert the expression  
- prints the resulting postfix expression  
- calls evaluatePostfix() to compute the result  
- prints the final evaluation result  

(D)Output  

Enter infix expression: (9+8)*3  
Postfix expression: 98+3*  
Evaluation result: 51  

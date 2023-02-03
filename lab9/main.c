#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/**
 * @brief Returns the priority of an operator for
 * the operators "+", "-", "*" and "/".
 * 
 * @param oper The operator
 * @return int The priority of oper
 */
int priority(char oper) {
	/*
		return 1 for addition and subtraction
		return 2 for multiplication and division
		return -1 otherwise
	*/
}

/**
 * @brief Converts given infix expression to a postfix
 * expression and returns it.
 * 
 * @param infix The infix expression
 * @param size The length of the infix expression string
 * @return char* Postfix version of infix
 */
char *infixToPostfix(char *infix, int size) {
	/*
		declare char ch, tmp, *p_tmp
		declare int flag
		declare char array postfix
		
		init flag as 1
		initialize an empty stack

		postfix <- malloc for a char array with size elements

		for i in range 0 -> size - 1 do
			ch <- index i of infix
			if ch is an operand or ' ' then
				place ch onto the postfix expression
			elseif ch is a left parenthesis
				p_tmp <- malloc for a char
				*p_tmp <- ch
				push p_tmp to the stack
			elseif ch is a right parenthesis
				tmp <- pop stack
				while tmp is not a left parenthesis do
					place tmp onto the postfix expression
					tmp <- pop stack
				endwhile
			elseif ch is an operator
				while stack is not empty and flag is 1 do
					tmp <- top of the stack
					if tmp is prior to ch then
						tmp <- pop stack
						place tmp onto the postfix expression
					else
						set flag to zero
					endif
				end while
				set flag to one
				p_tmp <- malloc for a char
				*p_tmp <- ch
				push p_tmp to the stack
			endif
		endfor

		while stack is not empty do
			ch <- pop stack
			place ch onto the postfix expression
		endwhile

		return postfix
	*/
}

/**
 * @brief Evaluates given postfix expression
 * 
 * @param postfix The postfix expression
 * @param size The length of the postfix expression string
 * @return int Result of the evaluation
 */
int evaluatePostfix(char *postfix, int size);

int main() {
	int size = 0, res;

	char *infix_exp = "3 + 5 * 2 + ( 7 * 3 + 1 ) * 2";
	printf("Infix : %s\n", infix_exp);
	while(infix_exp[size] != '\0') size++;

	char *postfix_exp = infixToPostfix(infix_exp, size);
	printf("Postfix : %s\n", postfix_exp);

	// res = evaluatePostfix(postfix_exp, size);
	// printf("Postfix Eval : %d\n", res);

	return 0;
}

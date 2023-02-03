#include <stdio.h>
#include <stdlib.h>
#include "stack.c"

int priority(char oper) {
	if(oper == '+' || oper == '-') {
		return 1;
	} else if(oper == '*' || oper == '/') {
		return 2;
	}
	return -1;
}

char *infixToPostfix(char *infix, int size) {
	LINKED_STACK s = linked_stack_init();
	int flag = 1, i, j = 0;
	char ch, tmp, *p_tmp;

	char *postfix = (char *)malloc(sizeof(char) * size);

	for(i = 0; i < size; i++) {
		ch = infix[i];
		if((ch >= 48 && ch <= 57) || ch == ' ') {						// Operand
			postfix[j] = ch;
			j++;
		} else if(ch == '(') {											// Opening Parenthesis
			p_tmp = (char *)malloc(sizeof(char));
			*p_tmp = ch;
			linked_stack_push(s, (void *)(p_tmp));
		} else if(ch == ')') {											// Closing Parenthesis
			tmp = *((char *)linked_stack_pop(s));
			while(tmp != '(') {
				postfix[j] = tmp;
				j++;
				tmp = *((char *)linked_stack_pop(s));
			}
		} else if(ch == '+' || ch == '-' || ch == '*' || ch == '/') {	// Operators
			while(!linked_stack_is_empty(s) && flag) {
				tmp = *((char *)linked_stack_top(s));
				if(priority(tmp) >= priority(ch)) {
					tmp = *((char *)linked_stack_pop(s));
					postfix[j] = tmp;
					j++;
				} else {
					flag = 0;
				}
			}
			flag = 1;
			p_tmp = (char *)malloc(sizeof(char));
			*p_tmp = ch;
			linked_stack_push(s, (void *)(p_tmp));
		}
	}

	while(!linked_stack_is_empty(s)) {
		ch = *((char *)linked_stack_pop(s));
		postfix[j] = ch;
		j++;
	}
	postfix[j] = '\0';
	return postfix;
}

int evaluatePostfix(char *postfix, int size) {
	int i, *tmp;
	char ch, op1, op2;
	
	LINKED_STACK s = linked_stack_init();
	
	for (i = 0; i < size; ++i) {
		ch = postfix[i];
		if (ch >= 48 && ch <= 57) {
			tmp = (int *)malloc(sizeof(int));
			*tmp = (char)(ch - '0');
			linked_stack_push(s, (void *)(tmp));
		}
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
			if (!linked_stack_is_empty(s)) {
				op1 = *((int *)linked_stack_pop(s));
				op2 = *((int *)linked_stack_pop(s));
				if (postfix[i] == '+') {
					tmp = (int *)malloc(sizeof(int));
					*tmp = op1 + op2;
					linked_stack_push(s, (void *)(tmp));
				} else if (postfix[i] == '-') {
					tmp = (int *)malloc(sizeof(int));
					*tmp = op1 - op2;
					linked_stack_push(s, (void *)(tmp));
				} else if (postfix[i] == '*') {
					tmp = (int *)malloc(sizeof(int));
					*tmp = op1 * op2;
					linked_stack_push(s, (void *)(tmp));
				} else if (postfix[i] == '/') {
					tmp = (int *)malloc(sizeof(int));
					*tmp = op1 / op2;
					linked_stack_push(s, (void *)(tmp));
				}
			}
		}
	}
	return *((int *)linked_stack_pop(s));
}

int main() {
	int size = 0, res;

	char *infix_exp = "3 + 5 * 2 + ( 7 * 3 + 1 ) * 2";
	printf("Infix : %s\n", infix_exp);
	while(infix_exp[size] != '\0') size++;

	char *postfix_exp = infixToPostfix(infix_exp, size);
	printf("Postfix : %s\n", postfix_exp);

	res = evaluatePostfix(postfix_exp, size);
	printf("Postfix Eval : %d\n", res);

	return 0;
}


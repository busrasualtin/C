#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

void *linked_stack_pop(LINKED_STACK stack) {
	LINKED_STACK_NODE node;
	void *res;

	if (stack->head != NULL) {
		node = stack->head;
		res = node->data;
		stack->head = node->next;
		free(node);
	} else {
		printf("Error @ linked_stack_pop: Empty stack is popped.\n");
	}
	return res;
}

void linked_stack_push(LINKED_STACK stack, void *data) {
	LINKED_STACK_NODE node = (LINKED_STACK_NODE) malloc(
			sizeof(LINKED_STACK_NODE_t));
	if (node != NULL) {
		node->data = data;
		node->next = stack->head;
		stack->head = node;
	} else {
		printf("Error @ linked_stack_push: Cannot allocatememory.\n");
	}
}

void *linked_stack_top(LINKED_STACK stack) {
	LINKED_STACK_NODE node;
	void *res = NULL;

	if (stack->head != NULL) {
		node = stack->head;
		res = node->data;
	}
	return res;
}

int linked_stack_size(LINKED_STACK s1) {
	LINKED_STACK_NODE node;
	int size = 0;
	node = s1->head;
	while (node != NULL) {
		node = node->next;
		size++;
	}
	return size;
}

int linked_stack_is_empty(LINKED_STACK stack) {
	void *elem = linked_stack_top(stack);
	return elem == NULL ? 1 : 0;
}

LINKED_STACK linked_stack_init() {
	LINKED_STACK new;

	new = (LINKED_STACK) malloc(sizeof(LINKED_STACK_t));
	if (new != NULL) {
		new->head = NULL;
	} else {
		printf("Error @ linked_stack_init: Memory allocation.");
	}
	return new;
}

void linked_stack_free(LINKED_STACK stack) {
	while (stack->head != NULL) {
		linked_stack_pop(stack);
	}
}

void linked_stack_print_char(LINKED_STACK stack) {
	printf("Stack:\n");
	LINKED_STACK_NODE node = stack->head;
	while(node != NULL) {
		printf("%c\n", *((char *)node->data));
		node = node->next;
	}
	printf("\n");
}

// Lab 11
// TODO: Fill these function blocks and test them in the main function.

#include <stdio.h>
#include <stdlib.h>
#include "linked_queue.h"

LINKED_QUEUE linked_queue_init()
{
	LINKED_QUEUE q = (LINKED_QUEUE)malloc(sizeof(LINKED_QUEUE_t));
	if(q != NULL){
		q->head = NULL;
		q->tail = NULL;
	}
	else{
		printf("linked_queue_init: malloc failed \n");
		exit(1);
	}
	return q;
}

void *linked_queue_dequeue(LINKED_QUEUE queue)
{
	LINKED_QUEUE_NODE res, node;
	node = (LINKED_QUEUE_NODE)queue->head;
	
	if(node != NULL){
		queue->head = node->next;
		res = node->data;
	}
	else{
		printf("Queue is empty! \n");
	}
	return res;
}

void linked_queue_enqueue(LINKED_QUEUE queue, void *data)
{
	LINKED_QUEUE_NODE node = (LINKED_QUEUE_NODE)malloc(sizeof(LINKED_QUEUE_NODE_t));
	node->data = data;
	node->next = NULL;
	
	if(queue->head != NULL){
		queue->tail->next = node;
		queue->tail = node;
	}
	else{
		queue->head = node;
		queue->tail = node;
	}
}

void linked_queue_print(LINKED_QUEUE queue)
{
	LINKED_QUEUE_NODE node = (LINKED_QUEUE_NODE) queue->head;
	while (node != NULL)
	{
		printf("%d ", *(int *)node->data);
		node = node->next;
	}
}

void linked_queue_free(LINKED_QUEUE queue)
{
	free(queue);
}

int linked_queue_is_empty(LINKED_QUEUE queue)
{
	if(queue->head == NULL) {
		return 1;
	}
	return 0;
}

int linked_queue_size(LINKED_QUEUE queue)
{
	LINKED_QUEUE_NODE node = (LINKED_QUEUE_NODE) queue->head;
	int cnt = 0;
	while (node != NULL)
	{
		node = node->next;
		cnt++;
	}
	return cnt;
}

int main()
{
	return 0;
}

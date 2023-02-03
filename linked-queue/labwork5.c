// Labwork 5
// TODO: Fill these function blocks and test them in the main function.

#include <stdio.h>
#include <stdlib.h>
#include "linked_queue.h"

#define N 10

//given by labwork4 maze example
typedef struct LINKED_STACK_NODE_s *LINKED_STACK_NODE;

typedef struct LINKED_STACK_NODE_s
{
    LINKED_STACK_NODE next;
    void *data;
}LINKED_STACK_NODE_t[1];

typedef struct LINKED_STACK_s
{
    LINKED_STACK_NODE head;
    int count;
}LINKED_STACK_t[1], *LINKED_STACK;

typedef struct
{
    int R;
    int C;
}POS_t[1], *POS;

LINKED_STACK stack_init(); //first
void stack_push(LINKED_STACK stack, void *data); //second
void *stack_pop(LINKED_STACK stack); //third
int is_empty(LINKED_STACK stack); //fourth
void stack_free(LINKED_STACK stack); //fifth

LINKED_STACK stack_init() //first
{
    LINKED_STACK stack = (LINKED_STACK)malloc(sizeof(LINKED_STACK_t));
    if (stack == NULL)
    {
        printf("\nproblem with initializing stack\n\n");
        return NULL;
    }
    stack->head = NULL;
    stack->count = 0;
    return stack;
}

void stack_push(LINKED_STACK stack, void *data)
{
    LINKED_STACK_NODE node = (LINKED_STACK_NODE)malloc(sizeof(LINKED_STACK_NODE_t));
    if (node == NULL)
    {
        printf("\nproblem with the creation of a node\n\n");
        return;
    }
    node->data = data;
    node->next = stack->head;
    stack->head = node;
    stack->count++;
}

void *stack_pop(LINKED_STACK stack)
{
    LINKED_STACK_NODE node;
    void *data = NULL;

    if (stack->head != NULL)
    {
        node = stack->head;
        data = node->data;
        stack->head = node->next;
        stack->count--;
        free(node);
    }
    else
    {
        printf("\nstack is empty:pop\n\n");
    }
    return data;
}

int is_empty(LINKED_STACK stack)
{
    return stack->head == NULL;
}

void stack_free(LINKED_STACK stack)
{
    while (is_empty(stack) == 0)
    {
        stack_pop(stack);
    }
    free(stack);
}




int *init_integer(int val)
{
	int *p =(int*)malloc(sizeof(int));
	*p = val;
	return p;
	
	// Fill this block.
	/*
	ptr <- memory allocation with one integer size
	ptr <- val
	return ptr
	*/
}

void bft(int graph[][N], int start_vertex)
{
	int i,v,size=N;
    LINKED_QUEUE queue = linked_queue_init();

    int *vmap = (int *)malloc(sizeof(int)*size);
    linked_queue_enqueue(queue, init_integer(start_vertex));
    vmap[start_vertex] =1;
    printf("%d ",start_vertex);
    fflush(stdout);

    while (!linked_queue_is_empty(queue))
    {
        v = (int)linked_queue_dequeue(queue);
        for (i=0;i<=size;i++)
        {
            if(graph[v][i] != 0 && vmap[i] != 1)
            {
                linked_queue_enqueue(queue,init_integer(i));
                vmap[i] = 1;
                printf("%d ",i);
                fflush(stdout);
            }
        }
    }
    free(vmap);
    
	// Fill this block.
	/*
	QUEUE queue
	size <- N
	vmap <- memory allocation with "size" size which every elements are zero
	enqueue(queue, init_integer(start_vertex))
	vmap[start_vertex] = 1
	print(start_vertex)
	fflush(stdout)
	while not isEmpty(queue) do
		v <- dequeue(queue);
		for i <- 0 to size do
			if graph[v][i] != 0 and vmap[i] != 1 then
				enqueue(queue, init_integer(i))
				vmap[i] = 1
				print(i)
				fflush(stdout)
			endif
		endfor
	endwhile
	free(vmap)
	*/
}

// inspired by assignment4 pseudocode, labwork5->bft function and labwork4 maze example..
void dft(int graph[][N], int start_vertex)
{
    LINKED_STACK s;
    int i,v,size=N;
    int *dmap = (int*)calloc(size,sizeof(int));
    
    stack_push (s, init_integer(start_vertex));
    dmap[start_vertex]=1;
    printf("%d ",start_vertex);
    fflush(stdout);
    
    while (!is_empty(s))
	{
        v = (int)stack_pop(s);
        for (i=0;i<size;++i)
		{
            if (graph[v][i]!=0 && dmap[i]!=1)
			{
                stack_push(s,init_integer(i));
                dmap[i]=1;
                printf("%d ",i);
                fflush(stdout);
            }
        }
    }
}

int main()
{
	int adjMatrix[N][N] = {
		{0, 1, 0, 0, 1, 0, 0, 1, 0},
		{0, 0, 0, 1, 1, 0, 0, 0, 0},
		{1, 0, 1, 0, 0, 1, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 0, 1},
		{0, 0, 1, 0, 0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0, 1, 0, 0, 0},
		{0, 0, 0, 1, 0, 1, 0, 1, 0},
		{0, 0, 0, 0, 0, 1, 0, 0, 1},
		{0, 1, 0, 1, 0, 1, 0, 1, 0},
		{0, 1, 0, 0, 1, 1, 0, 0, 0},
	};

	bft(adjMatrix, 0);
	dft(adjMatrix, 0);

	return 0;
}

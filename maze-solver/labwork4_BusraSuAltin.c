#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LINKED_STACK_NODE_s *LINKED_STACK_NODE;

typedef struct LINKED_STACK_NODE_s
{
    LINKED_STACK_NODE next;
    void *data;
} LINKED_STACK_NODE_t[1];

typedef struct LINKED_STACK_s
{
    LINKED_STACK_NODE head;
    int count;
} LINKED_STACK_t[1], *LINKED_STACK;

typedef struct
{
    int R;
    int C;
} POS_t[1], *POS;

LINKED_STACK stack_init();
void stack_free(LINKED_STACK stack);
void stack_push(LINKED_STACK stack, void *data);
void *stack_pop(LINKED_STACK stack);
void *stack_top(LINKED_STACK stack);
int is_empty(LINKED_STACK stack);

int is_empty(LINKED_STACK stack)
{
    return stack->head == NULL;
}

LINKED_STACK stack_init()
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

void stack_free(LINKED_STACK stack)
{
    while (is_empty(stack) == 0)
    {
        stack_pop(stack);
    }
    free(stack);
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

void *stack_top(LINKED_STACK stack)
{
    LINKED_STACK_NODE node;
    void *data = NULL;

    if (stack->head != NULL)
    {
        data = stack->head->data;
    }
    else
    {
        printf("\nstack is empty:top\n\n");
    }
    return data;
}

void solve_maze()
{
    int M[8][8] = {
            /* R\C   0  1  2  3  4  5  6  7 */
            /* 0 */ {0, 0, 0, 1, 0, 0, 0, 0},
            /* 1 */ {0, 1, 1, 1, 0, 0, 1, 0},
            /* 2 */ {0, 1, 0, 1, 0, 0, 1, 0},
            /* 3 */ {0, 1, 0, 1, 1, 1, 1, 0},
            /* 4 */ {0, 1, 0, 0, 0, 0, 1, 1},
            /* 5 */ {0, 1, 1, 0, 1, 1, 1, 0},
            /* 6 */ {0, 0, 0, 0, 1, 0, 0, 0},
            /* 7 */ {0, 0, 0, 0, 1, 0, 0, 0},
    };
    int I, J, R = 0, C = 3;
    LINKED_STACK stack;
    POS pos = (POS)malloc(sizeof(POS));
    int flag;
    stack = stack_init();

    M[R][C]=7;
    do
    {
        pos->C = C;
        pos->R = R;
        stack_push(stack,pos);

        if(pos->R == R-2 && pos->C == C-2)
        {
            break;
        }
        //up
        if(pos->R-1 >= 1 && M[pos->R-1][pos->C] == 1)
        {
            pos->R--;
            M[pos->R][pos->C]=7;
            stack_push(stack,pos);
            continue;
        }

        //down
        if(pos->R+1 < R-1 && M[pos->R+1][pos->C] == 1)
        {
            pos->R++;
            M[pos->R][pos->C]=7;
            stack_push(stack,pos);
            continue;
        }

        //left
        if(pos->C-1 >= 1 && M[pos->R][pos->C-1] == 1)
        {
            pos->C--;
            M[pos->R][pos->C]=7;
            stack_push(stack,pos);
            continue;
        }

        //right
        if(pos->C+1 < C-1 && M[pos->R][pos->C+1] == 1)
        {
            pos->C++;
            M[pos->R][pos->C]=7;
            stack_push(stack,pos);
            continue;
        }

        if(is_empty(stack))
        {
            printf("there is no exit");
        }
        else{
            printf("the path is:\n");
            for(I=0;I<8;I++)
            {
                for(J=0;J<8;J++)
                {
                    if(M[I][J]==0)
                        printf(" # "); //WALLS
                    else if(M[I][J]==1)
                        printf(" . "); //ROAD
                    else if(M[I][J]==7)
                        printf(" + "); //STARTING POINT
                    else
                        printf("   ");

                }
                printf("\n");
            }

        }
        // TODO: Fill this block.
    } while (R != 7 && C != 7 && R != 0 && C != 0);
}
int main()
{
    solve_maze();
    return 0;
}

/*
 * REFERENCES
 * https://www.programmersought.com/article/75785336246/
 * https://www.geeksforgeeks.org/rat-in-a-maze-backtracking-using-stack/
 * */
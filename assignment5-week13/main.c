#include<stdio.h>
#include"linked_list.h"

void print_int(void *p)
{
	int a = (int)p;
	printf("%d", a);
}

void linked_list_print(LINKED_LIST list, void (*print_data)(void *))
{
	LINKED_LIST_NODE walker;
	walker = list->head;
	while(walker != NULL) {
		print_data(walker->data);
		printf(" ");
		walker = walker->next;
	}
	printf("\n");
}

int linked_list_remove___nullablelist(LINKED_LIST list, int idx, void **pdata)
{
	LINKED_LIST_NODE walker, tmp;
	void *data;
	int i;
	int e;
	data = NULL;
	e = 0;
	if(idx == 0 && list->head != NULL) {
		tmp = list->head;
		list->head = tmp->next;
		data = tmp->data;
		free(tmp);
		e = 1;
	}
	else {
		walker = list->head;
		idx--;
		for(i=0; i<idx && walker->next!=NULL; i++) {
			walker = walker->next;
		}
		if(walker != NULL && walker->next != NULL) {
			tmp = walker->next;
			walker->next = tmp->next;
			data = tmp->data;
			free(tmp);
			e = 1;
		}
	}
	if(pdata != NULL) {
		*pdata = data;
	}
	return e;
}


int main()
{
	LINKED_LIST l = linked_list_init();
	
	printf("remove: 0\n");
	linked_list_remove(l, 0);
	linked_list_print(l, &print_int);
	
	printf("prepend: 7 times\n");
	linked_list_prepend(l, (void *)0);
	linked_list_prepend(l, (void *)1);
	linked_list_prepend(l, (void *)2);
	linked_list_prepend(l, (void *)3);
	linked_list_prepend(l, (void *)4);
	linked_list_prepend(l, (void *)5);
	linked_list_prepend(l, (void *)6);
	linked_list_print(l, &print_int);
	
	printf("remove: -1, 7\n");
	linked_list_remove(l, -1);
	linked_list_remove(l, 7);
	linked_list_print(l, &print_int);
	
	printf("remove: 3\n");
	linked_list_remove(l, 3);
	linked_list_print(l, &print_int);
	
	printf("remove: 0\n");
	linked_list_remove(l, 0);
	linked_list_print(l, &print_int);
	
	printf("remove: 4\n");
	linked_list_remove(l, 4);
	linked_list_print(l, &print_int);
	
	printf("remove: 0,0,0\n");
	linked_list_remove(l, 0);
	linked_list_remove(l, 0);
	linked_list_remove(l, 0);
	linked_list_print(l, &print_int);
	
	printf("remove: 0\n");
	linked_list_remove(l, 0);
	linked_list_print(l, &print_int);
	
	printf("remove: 0\n");
	linked_list_remove(l, 0);
	linked_list_print(l, &print_int);
	
	linked_list_free(l);
	
	return 0;
}


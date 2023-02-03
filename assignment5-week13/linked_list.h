#ifndef ___LINKED_LIST_H___
#define ___LINKED_LIST_H___

#include<stdlib.h>


typedef struct LINKED_LIST_NODE_s *LINKED_LIST_NODE;
typedef struct LINKED_LIST_NODE_s {
	LINKED_LIST_NODE next;
	void *data;
} LINKED_LIST_NODE_t[1];

typedef struct LINKED_LIST_s *LINKED_LIST;
typedef struct LINKED_LIST_s {
	LINKED_LIST_NODE head;
} LINKED_LIST_t[1];

LINKED_LIST linked_list_init();
void linked_list_free(LINKED_LIST list);
int linked_list_prepend(LINKED_LIST list, void *data);
int linked_list_append(LINKED_LIST list, void *data);
int linked_list_insert(LINKED_LIST list, void *data, int idx);
void *linked_list_set(LINKED_LIST list, void *data, int idx);
void *linked_list_get(LINKED_LIST list, int idx);
void *linked_list_remove(LINKED_LIST list, int idx);
void linked_list_removeall(LINKED_LIST list);
void linked_list_concatenate(LINKED_LIST list, LINKED_LIST list2);

LINKED_LIST linked_list_init()
{
	LINKED_LIST list;
	list = (LINKED_LIST)malloc(sizeof(LINKED_LIST_t));
	if(list != NULL) {
		list->head = NULL;
	}
	return list;
}

void linked_list_free(LINKED_LIST list)
{
	free(list);
}

int linked_list_prepend(LINKED_LIST list, void *data)
{
	LINKED_LIST_NODE n;
	int z;
	z = 0;
	n = (LINKED_LIST_NODE)malloc(sizeof(LINKED_LIST_NODE_t));
	if(n != NULL) {
		n->data = data;
		n->next = list->head;
		list->head = n;
		z = 1;
	}
	return z;
}

/* for nonnullable lists */
void *linked_list_set(LINKED_LIST list, void *data, int idx)
{
	LINKED_LIST_NODE walker, tmp;
	void *olddata;
	int i;
	olddata = NULL;
	if(idx == 0 && list->head != NULL) {
		tmp = list->head;
		olddata = tmp->data;
		tmp->data = data;
	}
	else {
		walker = list->head;
		idx--;
		for(i=0; i<idx && walker->next!=NULL; i++) {
			walker = walker->next;
		}
		if(walker != NULL && walker->next != NULL) {
			tmp = walker->next;
			olddata = tmp->data;
			tmp->data = data;
		}
	}
	return olddata;
}

/* for nonnullable lists */
void *linked_list_remove(LINKED_LIST list, int idx)
{
	LINKED_LIST_NODE walker, tmp;
	void *data;
	int i;
	data = NULL;
	if(idx == 0 && list->head != NULL) {
		tmp = list->head;
		list->head = tmp->next;
		data = tmp->data;
		free(tmp);
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
		}
	}
	return data;
}

#endif


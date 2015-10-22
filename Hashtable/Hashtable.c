#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hashtable.h"

int hash(char* str) {
	if(str != NULL) {
		int sum = 0;
		for(; *str != '\0'; str++) {
			sum += *str;
		}
		return sum % TABLE_MAXSIZE; 
	}
	return 0;
}

struct Hashtable *Hashtable_init(void) {
	struct Hashtable *table = (struct Hashtable *)malloc(sizeof(struct Hashtable));
	
	int i;
	for(i = 0; i < TABLE_MAXSIZE; i++)
		table->data_lists[i] = HLinkedList_init();
	table->size = 0;

	return table;
}

void Hashtable_add(struct Hashtable *table, CellIdentifier identifier, CellType data) {
	struct Cell cell;
	strcpy(cell.identifier, identifier);
	cell.data = data;

	HLinkedList_add(table->data_lists[hash(identifier)], HNode_init(cell));
}

int Hashtable_mem(struct Hashtable *table, CellIdentifier identifier) {
	if(table->data_lists[hash(identifier)]->size == 0)
		return 0;
	
	struct HNode *node = table->data_lists[hash(identifier)]->head;
	while(strcmp(node->data.identifier, identifier) != 0) {
		if(node == NULL)
			return 0;
		else
			node = node->next;
	}

	return 1;
}

CellType Hashtable_get(struct Hashtable *table, CellIdentifier identifier) {
	if(table->data_lists[hash(identifier)]->size == 0)
		return NULL;

	struct HNode *node = table->data_lists[hash(identifier)]->head;
	while(strcmp(node->data.identifier, identifier) != 0) {
		node = node->next;

		if(node == NULL)
			return NULL;
	}
	
	return node->data.data;
}

void Hashtable_cleanup(struct Hashtable *table) {
	int i;
	for(i = 0; i < TABLE_MAXSIZE; i++)
		HLinkedList_cleanup(table->data_lists[i]);
	free(table);	
}

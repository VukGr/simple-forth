#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdio.h>
#include <stdlib.h>

#define TABLE_MAXSIZE 500

typedef char CellIdentifier[256];
typedef char *CellType;

struct Cell {
	CellIdentifier identifier;
	CellType data;
};

#include "HLinkedList.h"	/* A hack so I don't have to define the hashtable
							   cell in the LinkedList header					*/

struct Hashtable {
	struct HLinkedList *data_lists[TABLE_MAXSIZE];
	int size;
};

int hash(char* str);
struct Hashtable *Hashtable_init(void);
void Hashtable_add(struct Hashtable *table, CellIdentifier identifier, CellType data);
int Hashtable_mem(struct Hashtable *table, CellIdentifier identifier);
CellType Hashtable_get(struct Hashtable *table, CellIdentifier identifier);
void Hashtable_cleanup(struct Hashtable *table);

#endif //HASHTABLE_H

#include <stdio.h>
#include <assert.h>
#include "Hashtable.h"

int main(void) {
	struct Hashtable *table = Hashtable_init();

	printf("Hash test: %s = %d, %s = %d, %s = %d\n", 
					"test", hash("test"), "I like pies", hash("I like pies"), "asdf", hash("asdf"));

	printf("Hashtable_add test.\n");

	Hashtable_add(table, "test", 123);
	Hashtable_add(table, "asdf", 321);
	Hashtable_add(table, "ghjk", 213);

	printf("Hashtable_mem test.\n");

	assert(Hashtable_mem(table, "test"));
	assert(Hashtable_mem(table, "asdf"));
	assert(Hashtable_mem(table, "ghjk"));
	assert(!Hashtable_mem(table, "pies"));

	printf("Hashtable_get test.\n");

	assert(Hashtable_get(table, "test") == 123);
	assert(Hashtable_get(table, "asdf") == 321);
	assert(Hashtable_get(table, "ghjk") == 213);

	assert(!Hashtable_get(table, "pies"));

	printf("End.\n");

	return 0;
}

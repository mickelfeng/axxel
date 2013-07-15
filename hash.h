
/**
 *
 * Axxel - Acl memory caching
 *
 * Copyright (c) 2013 Axxel Team
 *
 * Use and distribution licensed under the MIT license.
 * See the LICENSE file for full text.
 *
 * Authors: Andres Gutierrez <andres@phalconphp.com>
 */

#ifndef P_HASH_FUNCS

#define P_HASH_FUNCS

struct p_hash_node {
	char *key;
	unsigned int key_length;
	void *data;
	struct p_hash_node *next;
};

typedef struct _p_hash_table {
	size_t size;
	size_t num_elements;
	struct p_hash_node **nodes;
	unsigned long (*hashfunc)(const char *, unsigned int);
} p_hash_table;

unsigned long hashfunc_three(const char *key1, unsigned int key_length1, const char *key2, unsigned int key_length2, const char *key3, unsigned int key_length3);

p_hash_table *p_hash_table_create(size_t size, unsigned long (*hashfunc)(const char *, unsigned int));
void p_hash_table_destroy(p_hash_table *p_hash_table);
int p_hash_table_insert_quick(p_hash_table *hash_table, const char *key, unsigned int key_length, void *data, size_t hash_key);
int p_hash_table_insert(p_hash_table *p_hash_table, const char *key, unsigned int key_length, void *data);
int p_hash_table_remove(p_hash_table *p_hash_table, const char *key, unsigned int key_length);
void *p_hash_table_get(p_hash_table *p_hash_table, const char *key, unsigned int key_length);
int p_hash_table_exists(p_hash_table *p_hash_table, const char *key, unsigned int key_length);
int p_hash_table_resize(p_hash_table *p_hash_table, size_t size);
double p_hash_table_empty_ratio(p_hash_table *hash_table);

#endif
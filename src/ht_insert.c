/*
** EPITECH PROJECT, 2025
** LOUIS
** File description:
** ht_insert
*/

#include "../include/hashtable.h"
#include "../include/miniprintf.h"
#include "../include/tools.h"

static int create_entry(entry_t **entry, char *key, char *value)
{
    *entry = malloc(sizeof(entry_t));
    if (!*entry)
        return -1;
    (*entry)->key = my_strdup(key);
    (*entry)->value = my_strdup(value);
    if (!(*entry)->key || !(*entry)->value) {
        free((*entry)->key);
        free((*entry)->value);
        free(*entry);
        return -1;
    }
    return 0;
}

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    int hashed_key;
    int index;
    entry_t *entry;

    if (!ht || !key || !value)
        return -1;
    hashed_key = ht->hash(key, ht->size);
    index = hashed_key % ht->size;
    if (index < 0 || index >= ht->size)
        return -1;
    if (create_entry(&entry, key, value) == -1)
        return -1;
    entry->next = ht->entries[index];
    ht->entries[index] = entry;
    return 0;
}

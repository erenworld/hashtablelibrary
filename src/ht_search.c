/*
** EPITECH PROJECT, 2025
** LOUIS
** File description:
** ht_search
*/

#include "../include/hashtable.h"
#include "../include/miniprintf.h"
#include "../include/tools.h"

char *ht_search(hashtable_t *ht, char *key)
{
    int index = 0;
    entry_t *entry;

    if (!ht || !key)
        return 0;
    index = ht->hash(key, ht->size) % ht->size;
    entry = ht->entries[index];
    while (entry != NULL) {
        if (my_strcmp(entry->key, key) == 0) {
            return entry->value;
        }
        entry = entry->next;
    }
    return 0;
}

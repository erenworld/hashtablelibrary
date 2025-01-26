/*
** EPITECH PROJECT, 2025
** LOUIS
** File description:
** ht_delete
*/

#include "../include/hashtable.h"
#include "../include/miniprintf.h"
#include "../include/tools.h"

static int ht_delete_entry(entry_t **head, char *key)
{
    entry_t *prev = 0;
    entry_t *entry = *head;

    while (entry && my_strcmp(entry->key, key) != 0) {
        prev = entry;
        entry = entry->next;
    }
    if (!entry)
        return -1;
    if (prev)
        prev->next = entry->next;
    else
        *head = entry->next;
    free(entry->key);
    free(entry->value);
    free(entry);
    return 0;
}

int ht_delete(hashtable_t *ht, char *key)
{
    int index = 0;

    if (!ht || !key) {
        return -1;
    }
    index = ht->hash(key, ht->size) % ht->size;
    return ht_delete_entry(&ht->entries[index], key);
}

/*
** EPITECH PROJECT, 2025
** LOUIS
** File description:
** ht_dump
*/

#include "../include/hashtable.h"
#include "../include/miniprintf.h"
#include "../include/tools.h"

void ht_dump(hashtable_t *ht)
{
    int hashed_key = 0;
    entry_t *entry = 0;

    if (!ht)
        return;
    for (int i = 0; i < ht->size; i++) {
        mini_printf("[%d]:", i);
        entry = ht->entries[i];
        while (entry) {
            hashed_key = ht->hash(entry->key, ht->size);
            mini_printf("\n> %d - %s", hashed_key, entry->value);
            entry = entry->next;
        }
        mini_printf("\n");
    }
}

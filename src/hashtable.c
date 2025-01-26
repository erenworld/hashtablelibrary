/*
** EPITECH PROJECT, 2024
** SECURED
** File description:
** HASHTABLE
*/
#include "../include/hashtable.h"
#include "../include/miniprintf.h"
#include "../include/tools.h"

int hash(char *key, int len)
{
    unsigned long int value = 5381;

    if (!key || len <= 0)
        return 0;
    for (int i = 0; key[i] != '\0'; i++) {
        value = (value << 5) + value + key[i];
        value %= 2147483647;
    }
    return value;
}

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *hashtable = malloc(sizeof(hashtable_t));

    if (!hashtable)
        return NULL;
    if (len <= 0 || !hash) {
        return NULL;
    }
    hashtable->size = len;
    hashtable->hash = hash;
    hashtable->entries = malloc(sizeof(entry_t *) * len);
    if (!hashtable->entries) {
        free(hashtable);
        return NULL;
    }
    for (int i = 0; i < len; i++) {
        hashtable->entries[i] = NULL;
    }
    return hashtable;
}

void delete_hashtable(hashtable_t *ht)
{
    entry_t *entry;
    entry_t *next;

    if (!ht)
        return;
    for (int i = 0; i < ht->size; i++) {
        entry = ht->entries[i];
        while (entry != NULL) {
            next = entry->next;
            free(entry->key);
            free(entry->value);
            free(entry);
            entry = next;
        }
    }
    free(ht->entries);
    free(ht);
}

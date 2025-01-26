/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Secured
** File description:
** hashtable.h
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef HASHTABLE_H
    #define HASHTABLE_H

typedef struct entry_s {
    char *key;
    char *value;
    struct entry_s *next;
} entry_t;

typedef struct hashtable_s {
    entry_t **entries;
    int size;
    int (*hash)(char *, int);
} hashtable_t;

int hash(char *key, int len);

hashtable_t *new_hashtable(int (*hash)(char *, int), int len);
void delete_hashtable(hashtable_t *ht);
int ht_insert(hashtable_t *ht, char *key, char *value);
int ht_delete(hashtable_t *ht, char *key);
char *ht_search(hashtable_t *ht, char *key);
void ht_dump(hashtable_t *ht);

#endif

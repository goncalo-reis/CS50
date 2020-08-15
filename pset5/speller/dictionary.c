// Implements a dictionary's functionality

#include <stdbool.h>
#include <strings.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// number of words
int n_words = 0;

bool delete_list(node *head);

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // Get hash index for word
    int key = hash(word);
    // Iterate over chosen linked list
    node *tmp = table[key];
    while (tmp != NULL)
    {
        if (strcasecmp(tmp->word, word) == 0)
        {
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int value = tolower(word[0]);
    return value % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    //open file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    // Initialize hash table
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }
    //loop over each word in file
    char string[LENGTH + 1];
    while (fscanf(file, "%s\n", string) != EOF)
    {
        //create node for current word
        node *tmp = malloc(sizeof(node));
        strcpy(tmp->word, string);
        //get index of array for the current node
        int key = hash(string);
        //set the pointer structure
        if (table[key] == NULL)
        {
            tmp->next = NULL;
            table[key] = tmp;
        }
        else
        {
            tmp->next = table[key];
            table[key] = tmp;
        }
        n_words += 1;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return n_words;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        delete_list(table[i]);
        table[i] = NULL;
    }
    return true;
}

bool delete_list(node *head)
{
    if (head == NULL)
    {
        return true;
    }
    if (head->next == NULL)
    {
        free(head);
        return true;
    }
    if (delete_list(head->next))
    {
        free(head);
        return true;
    }
    return false;
}
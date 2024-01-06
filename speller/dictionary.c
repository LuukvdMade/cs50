// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
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

//my functions
bool searchList(node *n, const char *w);
bool deleteList(node *nptr);
void printLinkedList(node *ptr, int i);


// Number of buckets in hash table
const unsigned int N = 5000;
static int word_count;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{

    //make word lower case for comparing to dictionary
    char l_word[LENGTH + 1] = {0};
    char *ptrl_w;
    memcpy(l_word, word, LENGTH + 1);

    for (ptrl_w = l_word; *ptrl_w != '\0'; ptrl_w++)
    {
        *ptrl_w = tolower(*ptrl_w);
    }


    // hash word and get first item in list
    node *list;
    list = table[hash(l_word)];
    //check if empty
    if (list == NULL)
    {
        return false;
    }
    // recursively check each node
    return searchList(list, l_word);
}

bool searchList(node *n, const char *w)
{

    if (n->next == NULL) //checking last node in list
    {
        if (strcmp(w, n->word) == 0) // 0 -> equal
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    else if (strcmp(w, n->word) == 0)
    {
        return true;
    }
    else
    {
        return searchList(n->next, w);
    }
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int hash = 401;
    int c;

    while (*word != '\0')
    {
        hash = ((hash << 4) + (int)(*word)) % N;
        word++;
    }

    return hash % N;

}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    //open file, confirm OK
    FILE *inptr = fopen(dictionary, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s", dictionary);
        return false;
    }
    word_count = 0;
    char c;
    char dword[LENGTH + 1] = {0};
    int c_index = 0; //character index
    //read file
    while (fread(&c, sizeof(char), 1, inptr) == 1)
    {
        if (c_index != 0 && c == '\n') //im not sure which signifies end of wrd in dictionary
        {
            //terminate dword
            dword[c_index] = '\0';
            word_count++;

            //make new node
            node *n = malloc(sizeof(node));
            strcpy(n->word, dword);
            n->next = NULL;
            int hi = hash(dword);
            if (table[hi] == NULL)
            {
                table[hi] = n;
            }
            else //add node to head
            {
                n->next = table[hi];
                table[hi] = n;
            }
            //reset for next word
            c_index = 0;
            memset(dword, '\0', LENGTH);
        }
        else if (c != '\n') //if new line, skip - add nothing to array
        {
            c = tolower(c); //ensure everyting lowercase
            dword[c_index] = c;
            c_index++;
        }
    }
    fclose(inptr);
    return true;
}

void printLinkedList(node *ptr, int i)
{
    if (ptr == NULL) //this index in hash table hasn't been touched
    {
        printf("NULL\n");
        return;
    }
    else if (ptr->next == NULL)//ptr is last node in linked list
    {
        printf("T%i->:w=%s @%p\n", i, ptr->word, ptr);
        return;
    }
    i = i + 1;
    printLinkedList(ptr->next, i);
    printf("T%i->:w=%s @%p\n", i, ptr->word, ptr);
    return;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    //loop through array and check if any bucket has a list in int
    for (int i = 0; i < N; i++)
    {
        if (table[i] != NULL) //check if ptr goes to anything
        {
            deleteList(table[i]);
            table[i] = NULL;
        }
    }

    //confirm all linkedlist form hash table deleted
    for (int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            return false;
        }
    }
    return true;
}

bool deleteList(node *nptr)
{
    if (nptr->next == NULL)
    {
        free(nptr);
        nptr = NULL;
        return true;
    }
    //recursively delete parents in node

    deleteList(nptr->next);

    //delete child node
    free(nptr);
    nptr = NULL;
    return true;
}

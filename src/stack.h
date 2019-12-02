/* 
 * Rudiments of a char* Stack Structure.
 *
 * Implemented with a singly-linked list.
 */

#include <stdlib.h>

/*
 * Stack is the user-facing data struct.
 */
typedef struct { 
    struct StackItem *top;
} Stack;

/*
 * StackItem is the internal node stored per record.
 */
typedef struct StackItem {
    struct StackItem *next;
    char *value;
} StackItem;

/* Create a stack on the heap. Must later be destroyed! */
Stack* Stack_create();

/* Push a char* onto the Stack. */
void Stack_push(Stack *s, const char *str);

/* Peek the length of the top char* stored on Stack */
size_t Stack_peeksize(Stack *s);

/* Pop a char* off of the Stack and copy it to buffer. */
void Stack_pop(Stack *s, char* buffer);

/* Destroy a Stack by freeing its memory. */
void Stack_destroy(Stack *s);

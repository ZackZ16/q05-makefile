#include <string.h>

#include "stack.h"

/* === Internal Functions === */

StackItem* StackItem_create();
void StackItem_destroy(StackItem *si);

/* === Stack Function Implementations === */

Stack* Stack_create() {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

void Stack_push(Stack *s, const char *str) {
    StackItem *item = StackItem_create();
    item->next = s->top;
    size_t size = strlen(str);
    item->value = (char *)malloc(size * sizeof(char) + 1);
    strcpy(item->value, str);
    s->top = item;
}

size_t Stack_peeksize(Stack *s) {
    if (s->top == NULL) {
        return 0;
    } else {
        return sizeof(s->top->value);
    }
}

void Stack_pop(Stack *s, char* buffer) {
    StackItem *top = s->top;
    s->top = top->next;
    strcpy(buffer, top->value);
    StackItem_destroy(top);
}

void Stack_destroy(Stack *s) {
    StackItem *cursor = s->top;
    while (cursor != NULL) {
        StackItem *last = cursor;
        cursor = last->next;
        StackItem_destroy(last);
    }
    free(s);
}

/* === Internals === */

StackItem* StackItem_create() {
    return (StackItem*)(malloc(sizeof(StackItem)));
}

void StackItem_destroy(StackItem *si) {
    free(si->value);
    free(si);
}

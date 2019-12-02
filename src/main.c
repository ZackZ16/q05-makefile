#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

#define BUFSIZE 16

int main()
{
    Stack *s = Stack_create();
    Stack_push(s, "foo");
    Stack_push(s, "bar");
    Stack_push(s, "baz");
    Stack_push(s, "boz");
    Stack_push(s, "foz");

    char buffer[BUFSIZE];
    Stack_pop(s, buffer);
    printf("%s\n", buffer);

    Stack_pop(s, buffer);
    printf("%s\n", buffer);

    Stack_pop(s, buffer);
    printf("%s\n", buffer);

    Stack_destroy(s);
}

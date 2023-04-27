#include <stdio.h>
#include <stdlib.h>
#include "file_path.h"

// push an item onto the stack
void push(struct stack *s, int item) {
    if (is_full(s)) {
        printf("Error: Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    s->top++;
    s->data[s->top] = item;
}

// pop an item off the stack
int pop(struct stack *s) {
    if (is_empty(s)) {
        printf("Error: Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    int item = s->data[s->top];
    s->top--;
    return item;
}
#include <stdio.h>
#include <stdlib.h>
#include "file_path.h"

// push an item onto the file_path
void push(struct file_path *s, int item) {
    if (s->cur == 1023 - 1) {
        printf("Error: file_path overflow\n");
        exit(EXIT_FAILURE);
    }
    s->cur++;
    s->path[s->cur] = item;
}

// pop an item off the file_path
int pop(struct file_path *s) {
    if (is_empty(s)) {
        printf("Error: file_path underflow\n");
        exit(EXIT_FAILURE);
    }
    int item = s->path[s->cur];
    s->cur--;
    return item;
}

// initialize the stack
void init_stack(struct file_path *s) {
    s->cur = 0;
}

// check if the stack is empty/back at the home directory
int is_empty(struct file_path *s) {
    return (s->cur == 0);
}
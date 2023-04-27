#ifndef FILEPATH_H
#define FILEPATH_H
#define MAX_SIZE 1023

struct file_path {
    int path[MAX_SIZE];
    int cwd;

};

#endif

void push(struct stack *s, int item);
int pop(struct stack *s);
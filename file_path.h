#ifndef FILEPATH_H
#define FILEPATH_H
#define MAX_SIZE 1023

struct file_path {
    int path[MAX_SIZE];
    int cur;
};

void push(struct file_path *s, int item);
int pop(struct file_path *s);
void init_stack(struct file_path *s);
int is_empty(struct file_path *s); 

#endif

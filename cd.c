#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdint.h>
#include "uint32_to_str.h"
#include "file_path.h"


void cd(char* fileDir, struct file_path *cwd){
    uint32_t num;
    char fname[33];
    int found = 0;
    FILE *fp = fopen(uint32_to_str(cwd->cur), "rb");
    if (fp == NULL) {
        perror("Failed to open file");
        return;
    }
    while (!found && fread(&num, sizeof(num), 1, fp) == 1 &&
    fread(&fname, 32, 1, fp) == 1){
        if (strcmp(fname, fileDir)){
            found = 1;
        }
    }
    fclose(fp);
    if (found){
        push(cwd, num);
    } else{
        printf("Error: Unable to change directory");
    }
    return;
}
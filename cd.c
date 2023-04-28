#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdint.h>
#include "uint32_to_str.h"


/*
make sure we can go into that directory
    check if exist in that directory
change cur to that directory
*/
void cd(char* fileDir, int *cwd, char indlst[]){
    uint32_t num;
    char fname[33];
    FILE *fp = fopen(uint32_to_str(*cwd), "rb");
    if (fp == NULL) {
        perror("Failed to open file");
        return;
    }
    //read directory for number list and file name
    while (fread(&num, sizeof(num), 1, fp) == 1 &&
    fread(&fname, 32, 1, fp) == 1){
        //if is directory and name matches what user wants to cd to, set cwd to num
        if (!strcmp(fname, fileDir) && indlst[num] == 'd'){
            *cwd = num;
        }
    }
    fclose(fp);
    return;
}
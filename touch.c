#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdint.h>
#include "uint32_to_str.h"
void touch(char *fileDir, int *cwd, char indlst[], int* indSize){
    uint32_t num;
    char fname[33];
    FILE *fp = fopen(uint32_to_str(*cwd), "rb");
    if (fp == NULL) {
        perror("Failed to open file");
        return;
    }
    //check the directory to see if the file exists
    while (fread(&num, sizeof(num), 1, fp) == 1 &&
    fread(&fname, 32, 1, fp) == 1){
        //if is directory and name matches what user wants to cd to, set cwd to num
        if (!strcmp(fname, fileDir)){
            return;
        }
    }
    fclose(fp);

    // write to inodes list
    fp = fopen("inodes_list", "ab");
    if (fp == NULL) {
        perror("Failed to open file");
        return;
    }
    // fwrite(fp,"%uf", *indSize); // write the new inode # and name to inodes_list
    (*indSize) ++; // add one to the size of the list
    fclose(fp);
    return;
}
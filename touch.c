#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdint.h>
#include "uint32_to_str.h"
void touch(char *fileDir, int *cwd, char indlst[], int* indSize){
    printf("%d", *indSize);
    uint32_t num;
    char fname[33];
    int a, b;
    FILE *fp = fopen(uint32_to_str(*cwd), "rb+");
    if (fp == NULL) {
        perror("Failed to open file");
        return;
    }
    //check the directory to see if the file exists
    while ((a = fread(&num, sizeof(num), 1, fp)) == 1 &&
    ( b = fread(&fname, 32, 1, fp)) == 1){
        printf("%ld ", ftell(fp));
        //if is directory and name matches what user wants to cd to, set cwd to num
        if (!strcmp(fname, fileDir)){
            return;
        } 
    }
    fseek(fp, -16, SEEK_CUR);
    fwrite(indSize, sizeof(uint32_t), 1, fp); // write the new inode # and name to inodes_list
    fwrite(fname, sizeof(*fname), 1, fp); // write the new inode # and name to inodes_list
    fclose(fp);

    // write to inodes list
    fp = fopen("inodes_list", "ab");
    if (fp == NULL) {
        perror("Failed to open file");
        return;
    }
    fwrite(indSize, sizeof(uint32_t), 1, fp); // write the new inode # and name to inodes_list
    fwrite(&("f"), sizeof(char), 1, fp); // write the new inode # and name to inodes_list
    fclose(fp);

    // write to inodes list
    fp = fopen(uint32_to_str(*cwd), "ab");
    if (fp == NULL) {
        perror("Failed to open file");
        return;
    }
    
    (*indSize) ++; // add one to the size of the list
    fclose(fp);
    return;
}
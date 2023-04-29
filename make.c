#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdint.h>
#include "uint32_to_str.h"

/* includes functions to make directories and files */

void add_file_to_cwd(char *fileDir, int *cwd, int* indSize){
    //add file name to cwd
    FILE *fp = fopen(uint32_to_str(*cwd), "ab");
    fwrite(&(*indSize--), sizeof(uint32_t), 1, fp); // write the new inode # and name to cwd
    fwrite(fileDir, 32, 1, fp); // write the new inode # and name to cwd
    fclose(fp);
    return;
}

void append_inodes(int* indSize, char* fileType, char indlst[]){
    (*indSize) ++; // add one to the size of the list
    indlst[*indSize--] = fileType[0];
    // write to inodes list
    FILE *fp = fopen("inodes_list", "ab");
    if (fp == NULL) {
        perror("Failed to open file");
        return;
    }
    fwrite(&(*indSize--), sizeof(uint32_t), 1, fp); // write the new inode # and name to inodes_list
    fwrite(fileType, sizeof(char), 1, fp); // write the new inode # and name to inodes_list
    fclose(fp);
    return;
}
int check_dupe(int *cwd, char *fileDir){
    // return true if dupe
    uint32_t num;
    char fname[33];
    int a, b;
    FILE *fp = fopen(uint32_to_str(*cwd), "rb");
    if (fp == NULL) {
        perror("Failed to open file");
        return 1;
    }
    //check the directory to see if the file exists
    while ((a = fread(&num, sizeof(num), 1, fp)) == 1 &&
    ( b = fread(&fname, 32, 1, fp)) == 1){
        //if is directory and name matches what user wants to cd to, set cwd to num
        if (!strcmp(fname, fileDir)){// if equal == 0
            printf("unable to make file because file exist\n");
            return 1;
        } 
    }
    fclose(fp);
    return 0;
}
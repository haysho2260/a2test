#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdint.h>
#include "uint32_to_str.h"
#include "make.h"
/*
mkdir
    -check to see if directory already exists in the current directory
    record the current directory for ..
    makes a new inode in my ind list
    add to inodes_list (inode and file type d)
    make new file with fopen("", "wb")
    write to current directory with new inode number and file name
*/

void make_dir(char *fileDir, int *cwd, int* indSize);
void mkdir(char *fileDir, int *cwd, int* indSize, char indlst[]){
    if (!check_dupe(cwd, fileDir)){
        append_inodes(indSize, "d", indlst); // also increments indSize by 1
        add_file_to_cwd(fileDir, cwd, indSize);
        make_dir(fileDir, cwd, indSize);
    }
    return;
}
void make_dir(char *fileDir, int *cwd, int* indSize){
    // make new file (AKA directory)
    char name[11];
    sprintf(name, "%d", *indSize--);
    FILE *fp = fopen(name, "wb");
    if (fp == NULL) {
        perror("Failed to open file");
        return;
    }
    // # .
    fwrite(&(*indSize--), sizeof(uint32_t), 1, fp); // write the new inode # and name to new dir
    fwrite(&".", 32, 1, fp); // write the new inode # and name to new dir
    // # ..
    fwrite(cwd, sizeof(uint32_t), 1, fp); // write the cwd and name to new dir
    fwrite(&"..", 32, 1, fp); // write the name to new dir
    fclose(fp);
    return;
}
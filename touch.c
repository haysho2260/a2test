#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdint.h>
#include "uint32_to_str.h"
#include "file_path.h"


void touch(char* fileDir, struct file_path *cwd){
    uint32_t num;
    char fname[33];
    FILE *fp = fopen(uint32_to_str(cur), "rb+");
    if (fp == NULL) {
        perror("Failed to open file");
        return 1;
    }
    while (fread(&num, sizeof(num), 1, fp) == 1 &&
    fread(&fname, 32, 1, fp) == 1){
        if (strcmp(fileDir, fname)){
            // do nothing
            return
        }
    }
    if (num > 1023){
        printf("Not enough inodes");
    } else {
        // write to directory file
        fwrite(&(num + 1), sizeof(num), 1, fp); 
        fwrite(fileDir, 32, 1, fp);
        fclose(fp);
        FILE *fp = fopen("inodes_list", "rb+");
        if (fp == NULL) {
            perror("Failed to open file");
        }
        while (fread(&num, sizeof(num), 1, fp) == 1 &&
        fread(&fname, 32, 1, fp) == 1){

        }
    }

    fclose(fp);
    return 0;
    return;
}
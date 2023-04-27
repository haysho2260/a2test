#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdint.h>
#include "uint32_to_str.h"


int ls(){
    uint32_t num;
    char ch;
    char lst[1024] = {'\0'};

    FILE *fp = fopen("inodes_list", "rb");
    if (fp == NULL) {
        perror("Failed to open file");
        return 1;
    }

    // read values and get list of all inodes
    while (fread(&num, sizeof(num), 1, fp) == 1 &&
            fread(&ch, sizeof(ch), 1, fp) == 1){
        if ((num < 0) || (num > 1023)){
                printf("Inode: %d is invalid\n", num);
        } else {
            lst[num] = ch;
            // printf("num: %u, char: %c\n", num, ch);
        }
    }
    fclose(fp);
    
    char fname[32];
    int i, j;
    for (i = 0; i < 1024; i ++){
        if (lst[i] != '\0'){
            fp = fopen(uint32_to_str(i), "rb");
            // while ((c = fgetc(fp)))
            if (lst[i] == 'd'){
                fseek(fp, 76, SEEK_SET);  // move the file position indicator 64 bytes from the beginning of the file
            }
            // read values and get list of all inodes
            fread(&fname, 32, 1, fp);
            printf("%d %s\n", i, fname);
        }
    }
    fclose(fp);
    return 0;
}

